#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define sz(n) (int)n.size()-1

#define iter(it, second) for(auto it=second.begin(); it!=second.end(); it++)

vector<int> compressed(vector<int> &v){
    set<int> second;
    map<int, int> m;
    for (int i = 0; i <= sz(v); i++) {
        second.insert(v[i]);
    }

    int i = 0;
    iter(it, second) {
        m[*it] = i;
        i++;
    }

    for (int i = 0; i <= sz(v); i++) {
        v[i] = m[v[i]];
    }

    return v;
}

class Intervals {
	public:
		set<pair<int,int> > intervals;

		/*
		 * This method returns the interval to which a given element belongs.
		 * @param i: the element whose interval is to be fetched.
		 * return pair<int,int>: the interval to which the element belongs.
		 *
		 * NOTE: if the element does not belong to any interval, the method
		 * returns a pair of (-1, -1)
		 */
		pair<int,int> get_interval(int i) {
			auto it = intervals.lower_bound(make_pair(i,i));

			/* if the interval begins with the element. */
			if(it!=intervals.end() && it->first==i)
				return *it;

			/* if the first interval begins with an element greater than the element. */
			if(it==intervals.begin())
				make_pair(-1, -1);

			it--;

			/* if the interval contains the element. */
			if(it->first<=i && it->second>=i)
				return *it;

			return make_pair(-1, -1);
		}


		void remove_point(int i) {
			pair<int,int> interval = get_interval(i);

			/* if the interval does not contain the point, return. */
			if(interval.first==-1)
				return;

			// case 1: the interval begins and ends at i.
			if(interval.first==i && interval.second==i) {
				intervals.erase(interval);
				return;
			}

			// case 2: the interval begins at i.
			if(interval.first==i) {
				pair<int,int> temp = interval;
				temp.first++;

				intervals.erase(interval);
				intervals.insert(temp);
				return;
			}


			// case 3: the interval ends at i.
			if(interval.second==i) {
				pair<int,int> temp = interval;
				temp.second--;

				intervals.erase(interval);
				intervals.insert(temp);
				return;
			}


			// case 4: i lies in between the interval.
			intervals.insert(make_pair(interval.first, i-1));
			intervals.insert(make_pair(i+1, interval.second));
			intervals.erase(interval);
		}


		void add_interval(pair<int,int> i) {
			intervals.insert(i);
		}


		void remove_interval(pair<int,int> i) {
			intervals.erase(i);
		}

		void clear() {
			intervals.clear();
		}
};

Intervals intervals;

vector<int> v[1005];
vector<int> v2;
int pos[1005];


void init() {
	for (int i = 0; i <= 999; i++)
		v[i].clear();

	v2.clear();
}


void solve(int test_case) {
	init();

	int n;
	cin>>n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin>>a;
		v2.push_back(a);
	}

	v2 = compressed(v2);
	for (int i = 0; i <= sz(v2); i++) {
		v[v2[i]].push_back(i);
	}

	ll ans = 0;
	for (int i = 0; i <= sz(v2)-1; i++) {
		intervals.clear();
		intervals.add_interval(make_pair(i+1, sz(v2)));

		ll total = (sz(v2)-i)*(sz(v2)-i+1)/2;

		for (int j = 0; j <= 999; j++) {
			pos[j] = 0;
			while(pos[j]<=sz(v[j]) && v[j][pos[j]]<=i)
				pos[j]++;
		}

		// take the element into this interval
		for (int j = i; j <= sz(v2)-1; j++) {
			int cur = v2[j];
			while(pos[cur]<=sz(v[cur])) {
				pair<int, int> ret = intervals.get_interval(v[cur][pos[cur]]);

				// remove the pairs from this interval
				total -= (ret.second-ret.first+1)*(ret.second-ret.first+2)/2;

				// add the sum of new intervals.
				// case 1: if the removed point lies on the edge
				if(ret.first==v[cur][pos[cur]] || ret.second==v[cur][pos[cur]]) {
					total += (ret.second-ret.first)*(ret.second-ret.first+1)/2;
				}

				// if the point lies in between.
				else {
					ll first_len = v[cur][pos[cur]] - ret.first;
					ll second_len = ret.second - v[cur][pos[cur]];

					total += first_len*(first_len+1)/2;
					total += second_len*(second_len+1)/2;
				}

				intervals.remove_point(v[cur][pos[cur]]);
				pos[cur]++;
			}

			ans += total;
		}
	}
	cout << ans << endl;
}

int main() {
	int t = 1;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		solve(i);
	}
	return 0;
}
