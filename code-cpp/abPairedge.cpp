#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define MAX 100005
typedef long long ll;

typedef pair<ll, ll> pii;
pii E[MAX];
ll parent[MAX];
ll level[MAX];
ll W[MAX];


ll N, Q, a, b, e, u, v;
vector<ll> adj[MAX];


void dfs(ll i, ll par, ll lvl, ll wt){
    // Traverse tree and store level and parents
    parent[i] = par;
    level[i] = lvl;
    W[i] = 1;
    for (auto neigh : adj[i]){
        if (neigh != par){
            dfs(neigh, i, lvl + 1, 1);
            W[i] += W[neigh];
        }
    }
}


ll calc(ll u, ll v){
    ll up = level[u] > level[v] ? v : u;
    ll lo = up == u ? v : u;
    ll above = 0, low = 1;
    if (up != 1)
        above = W[1] - W[up];
    low = W[lo];
    if (W[up] - W[lo] > 0)
        above += W[up] -W[lo];
    // cout << above << " - " << low << endl;
    return above * low;
}

int main(){
    cin >> N >> Q;

    for (ll i = 1; i < N; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        E[i] = mp(a, b);
    }

    dfs(1, 1, 0, 1);
    while (Q--){
        cin >> e;
        u = E[e].first;
        v = E[e].second;
        cout << calc(u, v) << "\n";
    }

    return 0;
}
