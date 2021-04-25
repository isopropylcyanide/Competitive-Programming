// O(1) LCA using sparse table
#include <bits/stdc++.h>
using namespace std;

#define MAX 50001
#define MAX_LOG 16
typedef long long ll;

vector<vector<pair<ll, ll>> > adjList;
ll sq[MAX], D[MAX], parent[MAX], level[MAX];
vector<vector<ll> > P;

ll T, N, M, u, v, L;
ll root;

inline void addEdge(ll s, ll e, ll w){
    adjList[s].push_back(make_pair(e, w));
    adjList[e].push_back(make_pair(s, w));
}


void dfs(ll i, ll curDist, ll par, ll lvl){
    D[i] = curDist;
    parent[i] = par;
    level[i] = lvl;
    for (auto neigh : adjList[i]){
        if (neigh.first != par)
            dfs(neigh.first, curDist + neigh.second, i, lvl + 1);
    }
}

void preprocess(){
    //Every element in P[][] is -1 initially;
    //The first ancestor(2^0 th ancestor)
    //for every node is parent[node]
    for(int i = 1 ; i <= N ; ++i){
        P[i][0] = parent[i] ;
    }

    for(int j = 1; (1<<j) < N ; ++j){
        for(int i = 1 ; i <= N ; ++i){
            //If a node does not have a (2^(j-1))th ancestor
            //Then it does not have a (2^j)th ancestor
            //and hence P[i][j] should remain -1
            //Else the (2^j)th ancestor of node i
            //is the (2^(j-1))th ancestor of ((2^(j-1))th ancestor of node i)
            if(P[i][j-1] != -1){
                P[i][j] = P[P[i][j-1]][j-1] ;
            }
        }
    }
}

ll LCA(ll u , ll v){
    if(level[u] < level[v]){
        swap(u,v) ;
    }
    //u is the node at a greater depth/lower level
    //So we have to raise u to be at the same
    //level as v.
    ll dist = level[u] - level[v] ;
    while(dist > 0){
        ll raise_by = log2(dist);
        u = P[u][raise_by];
        dist -= (1<<raise_by) ;
    }

    if(u == v){
        return u ;
    }

    //Now we keep raising the two nodes by equal amount
    //Untill each node has been raised uptill its (k-1)th ancestor
    //Such that the (k)th ancestor is the lca.
    //So to get the lca we just return the parent of (k-1)th ancestor
    //of each node

    for(ll j = MAX_LOG ; j >= 0 ; --j){
        //Checking P[u][j] != P[v][j] because if P[u][j] == P[v][j]
        //P[u][j] would be the Lth ancestor such that (L >= k)
        //where kth ancestor is the LCA
        //But we want the (k-1)th ancestor.
        if((P[u][j] != -1) and (P[u][j] != P[v][j])){
            u = P[u][j] ;
            v = P[v][j] ;
        }
    }
    return parent[u] ; //or parent[v]
}

int __gcd(int a, int b){
    if (a < b){
        return __gcd(b, a);
    }
    if (b == 0){
        return a;
    }
    return __gcd(b, a % b);
}

int main(){
    scanf("%lld", &T);

    while(T--){
        scanf("%lld %lld",&N, &M);

        adjList.resize(MAX);
        P.resize(MAX, vector<ll>(MAX_LOG, -1));
        for (ll i = 0; i < MAX; i++){
            adjList[i].clear();
            P[i].clear();
        }

        for (ll i = 0; i < N -1; i++){
            scanf("%lld %lld %lld",&u, &v, &L);
            addEdge(u, v, L);
        }

        memset(sq, MAX, 0);
        memset(D, MAX, 0);
        memset(parent, MAX, 0);
        memset(level, MAX, 0);

        for (ll i = 0; i < M; i++){
            scanf("%lld", &sq[i]);
        }

        // find root of the tree. root is the one which has only one edge
        root = 1;
        dfs(root, 0, root, 0);
        preprocess();

        ll num = 0, deno = 1;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++){
                if (i == j)
                    continue;
                // find lca of sq[i] and sq[j]
                ll _lca = LCA(sq[i], sq[j]);
                ll dA = abs(D[_lca] - D[sq[i]]);
                ll dB = abs(D[_lca] - D[sq[j]]);
                num += dA + dB;
            }
        }

        deno = M * M;
        ll _g = __gcd(num, deno);
        num /= _g, deno /= _g;
        printf("%lld %lld\n",num, deno);
    }


    return 0;
}
