#include <bits/stdc++.h>
using namespace std;

#define MAX 50001
typedef long long ll;

vector<vector<pair<ll, ll>> > adjList;
ll parent[MAX], subtree[MAX], level[MAX];
bitset<MAX> bits;
/*
Key logic: Every node stores the number of nodes that are present in sq array and
are in its subtree. When removing an edge, remove the one which is at the lowest level
*/

typedef struct edge{
    ll u, v, l;
    edge(){}
    edge(ll a, ll b, ll c){
        u = a, v = b, l = c;
    }
}edge;
vector<edge> E;

ll T, N, M, u, v, L;
ll root, temp;

inline void addEdge(ll s, ll e, ll w){
    adjList[s].push_back(make_pair(e, w));
    adjList[e].push_back(make_pair(s, w));
}


void dfs(ll i, ll par, ll lvl){
    parent[i] = par;
    level[i] = lvl;
    subtree[i] = bits.test(i) ? 1 : 0;

    for (auto neigh : adjList[i]){
        if (neigh.first != par){
            dfs(neigh.first, i, lvl + 1);
            subtree[i] += subtree[neigh.first];
        }
    }
}

int main(){
    scanf("%lld", &T);

    while(T--){
        scanf("%lld %lld",&N, &M);

        adjList.resize(MAX);
        for (ll i = 0; i < MAX; i++)
            adjList[i].clear();

        E.clear();
        bits.reset();

        for (ll i = 0; i < N -1; i++){
            scanf("%lld %lld %lld",&u, &v, &L);
            E.push_back(edge(u, v, L));
            addEdge(u, v, L);
        }

        memset(parent, MAX, 0);
        memset(subtree, MAX, 0);
        memset(level, MAX, 0);

        for (ll i = 0; i < M; i++){
            scanf("%lld", &temp);
            bits.set(temp, 1);
        }
        // find root of the tree. root is the one which has only one edge
        root = 1;
        dfs(root, 0, root);

        // cout << "\n dist are: \n";
        // for (int i = 1; i <= N; i++)
        //     cout << i << " :  parent: " << parent[i] << " subtree: " << subtree[i] << endl;

        ll num = 0, deno = 1;
        for (auto edge : E){
            ll w = edge.l, u = edge.u, v = edge.v;
            ll inSub = level[v] > level[u] ? subtree[v] : subtree[u];
            num += w * inSub * (M - inSub);
            // printf("\nRemoving edge %lld - %lld (%lld) gives %lld and %lld",u, v, w, inSub, (M - inSub) );
        }
        num *= 2;
        deno = M * M;
        ll _g = __gcd(num, deno);
        num /= _g, deno /= _g;
        printf("%lld %lld\n",num, deno);
    }


    return 0;
}
