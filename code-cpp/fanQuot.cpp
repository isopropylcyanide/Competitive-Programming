#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> pis;

bool compare(const pis &a, const pis &b){
	if (a.first < b.first)
		return 0;
	else if (a.first == b.first)
		return a.second < b.second;
	return 1;
}

int main(){
	int n, k, f;
	string s;
	cin >> n >> k;

	vector<pis> p;
	for (int i = 0; i < n; i++){
		cin >> s >> f;
		p.push_back(make_pair(f, s));
	}
	sort(p.begin(), p.end(), compare);

    for (int i = 0; i < k; i++)
    	cout << p[i].second << endl;
    return 0;
}
