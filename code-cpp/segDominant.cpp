#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <cassert>
#include <unordered_map>
#define rf freopen("in.in", "r", stdin)
#define wf freopen("out.out", "w", stdout)
#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
using namespace std;
const int mx = 1e5 + 10;

struct node {
	unordered_map<int, int> CountOccurrences;
	int Dominant;
} SegTree[4*mx];

int n, q, a[mx];
vector<int> QueryRanges;

void build(int x, int y, int r) {
	if(x == y) {
		SegTree[r].CountOccurrences.clear();
		SegTree[r].CountOccurrences[a[x]] += 1;

		SegTree[r].Dominant = a[x];
		return;
	}

	int mid = (x+y) >> 1;
	build(x, mid, 2*r);
	build(mid+1, y, 2*r+1);

	int length = (y-x+1);
	SegTree[r].CountOccurrences.clear();

	unordered_map<int, int>::iterator it = SegTree[2*r].CountOccurrences.begin();
	while(it != SegTree[2*r].CountOccurrences.end()) {
		SegTree[r].CountOccurrences[it->first] += it->second;
		it++;
	}

	it = SegTree[2*r+1].CountOccurrences.begin();
	while(it != SegTree[2*r+1].CountOccurrences.end()) {
		SegTree[r].CountOccurrences[it->first] += it->second;
		it++;
	}

	if(SegTree[r].CountOccurrences[SegTree[2*r].Dominant] > (length/2)) {
		   SegTree[r].Dominant = SegTree[2*r].Dominant;

	} else if (SegTree[r].CountOccurrences[SegTree[2*r+1].Dominant] > (length/2)) {
			SegTree[r].Dominant = SegTree[2*r+1].Dominant;

	} else {
		SegTree[r].Dominant = -1;
	}

	return;
}

void update(int x, int y, int r, int idx, int val, int oldVal) {
	if(y < idx || x > idx) {
		return;
	}

	if(x == y) {
		assert(x == idx);

		SegTree[r].CountOccurrences.clear();

		a[idx] = val;
		SegTree[r].CountOccurrences[a[idx]] += 1;
		SegTree[r].Dominant = a[idx];

		return;
	}

	int mid = (x+y) >> 1;
	update(x, mid, 2*r, idx, val, oldVal);
	update(mid+1, y, 2*r+1, idx, val, oldVal);

	int length = (y-x+1);

	SegTree[r].CountOccurrences[oldVal] -= 1;
	SegTree[r].CountOccurrences[val] += 1;

	if(SegTree[r].CountOccurrences[SegTree[2*r].Dominant] > (length/2)) {
		   SegTree[r].Dominant = SegTree[2*r].Dominant;

	} else if (SegTree[r].CountOccurrences[SegTree[2*r+1].Dominant] > (length/2)) {
			SegTree[r].Dominant = SegTree[2*r+1].Dominant;

	} else {
		SegTree[r].Dominant = -1;
	}

	return;
}

void query(int x, int y, int r, int qs, int qe) {
	if(y < qs || qe < x) {
		return;
	}

	if(qs <=x && y<=qe) {
		QueryRanges.push_back(r);
		return;
	}

	int mid = (x+y) >> 1;
	query(x, mid, 2*r, qs, qe);
	query(mid+1, y, 2*r+1, qs, qe);
}

int main() {
	//rf;// wf;
	ios::sync_with_stdio(0);

	cin >> n >> q;
	rep(i, 1, n) {
		cin >> a[i];
	}

	build(1, n, 1);

	while(q--) {
		int type;
		cin >> type;

		switch (type) {
		case 1:
			int idx, val;
			cin >> idx >> val;
			update(1, n, 1, idx, val, a[idx]);

			break;

		case 2:
			int qs, qe, length, found;
			cin >> qs >> qe;

			length = qe - qs + 1;
			found = 0;

			QueryRanges.clear();
			query(1, n, 1, qs, qe);

			rep(i, 0, QueryRanges.size()-1) {
				int Count = 0;
				rep(j, 0, QueryRanges.size() - 1) {
					Count +=
						SegTree[QueryRanges[j]].CountOccurrences[SegTree[QueryRanges[i]].Dominant];
				}

				if(Count > length/2) {
					cout << "Yes\n";
					found = 1;
					break;
				}
			}

			if (!found) {
				cout << "No\n";
			}

			break;
		}
	}

	return 0;
}
