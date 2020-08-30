#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
const ll mod = 1e9+7;

int main(){
    ll N, M, T;
    cin >> T;
    while (T--){
        cin >> N >> M;
        vector<ll> dist(N, -1);
		vector<ll> cnt(N, 0);
        vector<vector<pair<ll,ll> > > G(N);
        ll u, v, w;

        for (ll i = 0; i < M; i++){
            cin >> u >> v >> w;
            G[u - 1].push_back(make_pair(v - 1, w));
            G[v - 1].push_back(make_pair(u - 1, w));
        }    

        priority_queue<pii,vector<pii>,greater<pii> > pq;
        dist[0] = 0;
        pq.push(make_pair(0, 0));

        while (!pq.empty()){
           pair<ll,ll> p=pq.top();
			pq.pop();
			ll r = p.second;
			ll d = p.first;
			for(ll i=0; i < G[r].size(); i++){
				ll c = G[r][i].first;
				ll w = G[r][i].second;
				if(dist[c] == -1 || dist[c] > d + w){
					dist[c] = d + w;
					pq.push(make_pair(dist[c], c));
					cnt[c] = 1;
				}
				else if(dist[c] == d + w){
					cnt[c]++;
				}
			}
        }

        ll res = 1;
        for (ll i = 0; i < N; i++){
            if (cnt[i] != 0)
            res = (res * cnt[i]) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}