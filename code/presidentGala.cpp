#include<bits/stdc++.h>
using namespace std;

#define long long long


const int MAX = 100000;
vector<vector<int>> g(MAX, vector<int>());
int a[MAX], dsu[MAX];
bool force[MAX];

int find_set(int v){
	if (v == dsu[v])
		return v;
	return dsu[v] = find_set(dsu[v]);
}

void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if (a != b)
		dsu[b] = a;
}

pair<long, long> Dfs(int x, int p){
	long s0 = 0, s1 = 0;
	for (auto e : g[x])
		if (e != p)
		{
			auto t = Dfs(e, x);
			s0 += t.first;
			s1 += max(t.first, t.second);
		}
	return make_pair(s1, force[x] ? s1 : max(s1, s0 + a[x]));
}

int main(){

    int n, m, u, v;
    cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		dsu[i] = i;
	}

	vector<pair<int, int>> b;
	for (int i = 0; i < m; i++){
        cin >> u >> v;
		if (find_set(u) == find_set(v))
			b.push_back(make_pair(u, v));
		else{
			g[u].push_back(v);
			g[v].push_back(u);
			union_sets(u, v);
		}
	}

	int bn = b.size();
	long ans = 0;
	for (int mask = 0; mask < 1 << bn; mask++){
		for (int i = 0; i < bn; i++)
			if ((mask >> i & 1) == 0){
				force[b[i].first] = true;
				force[b[i].second] = false;
			}
			else{
				force[b[i].first] = false;
				force[b[i].second] = true;
			}
		auto ret = Dfs(0, -1);
		ans = max(ans, max(ret.first, ret.second));
	}

	printf("%lld\n", ans);

	return 0;
}
