#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100005

vector< list <ll> > graph;
vector<ll> W; //denotes weight[i]

ll n, m, u, v, x, q, type;

bitset<MAX> bits;

ll query3(ll u){
    // report value of weight of node x
    return W[u];
}

void _dfs(ll i, ll query, ll x){
    // Mark
    if (bits.test(i) == 1)
        return;
    bits.set(i, 1);
    W[i] = query == 1 ? x : (W[i] > x ? x : W[i]);

    for (auto g : graph[i]){
        if (bits.test(g) == 0){
            W[g] = query == 1 ? x : (W[g] > x ? x : W[g]);
            _dfs(g, query, x);
        }
    }
}

void dfs(ll i, ll query, ll x){
    // dfs only when necessary
    bits.reset();
    _dfs(i, query, x);
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    W.resize(n + 1, 0);
    graph.resize(n + 1);

    for (ll i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
    }


    for (int i = 0; i < q; i++){
        cin >> type;
        switch (type){
        case 1:
            cin >> u >> x;
            // set x to all those reachable from u
            dfs(u, 1, x);
            break;

        case 2:
            cin >> u >> x;
            // set x to all those reachable from u and whose weight > x
            dfs(u, 2, x);
            break;

        case 3:
            // report value of weight of node x
            cin >> x;
            cout << query3(x) << "\n";
            break;
        }

    }
}
