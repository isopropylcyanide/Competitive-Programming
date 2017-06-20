#include <bits/stdc++.h>

using namespace std;

#define MAX 750005
#define MAX_LOG 20
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pll;

// graph
vector<pll> g[MAX];
ll parent[MAX], level[MAX];
vector<vector<ll> > P;
vector<ll> path;
// store edges for constant retrieval

map<pll, ll> edgeMap;

ll N, u, v, w, a, b, k, Q, _lca, lastAns = 0;
inline void addEdge(ll s, ll e, ll w){
    g[s].push_back(make_pair(e, w));
    g[e].push_back(make_pair(s, w));
}

void dfs(ll i, ll par, ll lvl){
    // Traverse tree and store level and parents
    parent[i] = par;
    level[i] = lvl;
    for (auto neigh : g[i]){
        if (neigh.first != par)
            dfs(neigh.first, i, lvl + 1);
    }
}

void preprocess(){
    // preprocess parent table
    for(int i = 1 ; i <= N ; ++i){
        P[i][0] = parent[i] ;
    }

    for(int j = 1; (1<<j) < N ; ++j){
        for(int i = 1 ; i <= N ; ++i){
            if(P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1] ;
        }
    }
}

ll LCA(ll u , ll v){
    // Finds lowest common ancestor in O(1)
    if(level[u] < level[v])
        swap(u,v) ;
    ll dist = level[u] - level[v] ;
    while(dist > 0){
        ll raise_by = log2(dist);
        u = P[u][raise_by];
        dist -= (1<<raise_by) ;
    }

    if(u == v)
        return u ;

    for(ll j = MAX_LOG ; j >= 0 ; --j){
        if((P[u][j] != -1) and (P[u][j] != P[v][j])){
            u = P[u][j] ;
            v = P[v][j] ;
        }
    }
    return parent[u] ; //or parent[v]
}


inline ll max(ll a, ll b){
    return a > b ? a : b;
}

void storePath(ll node, ll upto){
    // Store path starting from node till upto
    // if node == upto, return
    while (node != upto){
        path.push_back(edgeMap[mp(node, parent[node])]);
        node = parent[node];
    }
}

ll kthMinimum(ll k){
    // find kth minimum in path vector
    // return -1 if not possible
    if (k > path.size())
        return -1;
    nth_element(path.begin(), path.begin() + k - 1, path.end());
    return path[k -1];
}

int main(){
    scanf("%lld", &N);

    P.resize(MAX, vector<ll>(MAX_LOG, -1));

    for (int i = 0; i < N -1; i++){
        scanf("%lld %lld %lld",&u, &v, &w);
        addEdge(u, v, w);
        edgeMap[mp(u, v)] = w;
        edgeMap[mp(v, u)] = w;
    }

    ll root = 1;
    dfs(root, root, 0);
    preprocess();

    scanf("%lld",&Q);

    for (int i = 0; i < Q; i++){
        scanf("%lld %lld %lld",&a, &b, &k);
        a = ((a - 1 + max(0, lastAns)) % N) + 1;
        b = ((b - 1 + 2 * max(0, lastAns)) % N) + 1;
        k = ((k - 1 + 3 * max(0, lastAns)) % N) + 1;
        _lca = LCA(a, b);
        path.clear();

        storePath(a, _lca);
        if (a != b)
            storePath(b, _lca);
        lastAns = kthMinimum(k);
        printf("%lld\n", lastAns);
    }

    return 0;
}
