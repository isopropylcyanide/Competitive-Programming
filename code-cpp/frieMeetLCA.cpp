// O(sqrt h) LCA
#include <bits/stdc++.h>
using namespace std;

#define MAX 50005
typedef long long ll;

vector<vector<pair<ll, ll>> > adjList;
ll sq[MAX], D[MAX], parent[MAX], level[MAX], P[MAX];

ll T, N, M, u, v, L;
ll root;

inline void addEdge(ll s, ll e, ll w){
    adjList[s].push_back(make_pair(e, w));
    adjList[e].push_back(make_pair(s, w));
}

typedef struct qNode{
    ll i, lvl, par, curDist;
    qNode(){}
    qNode(ll a, ll b, ll c, ll d){
        i = a, lvl = b, par = c, curDist = d;
    }
}qNode;

void bfs(ll i, ll curDist, ll par, ll lvl){
    // bfs please

    queue<qNode> q;
    q.push(qNode(i, lvl, par, curDist));

    while (!q.empty()){
        qNode node = q.front();
        D[node.i] = node.curDist;
        parent[node.i] = node.par;
        level[node.i] = node.lvl;
        q.pop();

        for (auto neigh : adjList[node.i]){
            if (neigh.first != node.par)
                q.push(qNode(neigh.first, node.lvl + 1, node.i, node.curDist +neigh.second));
        }
    }
}

void dfs_sqrt(ll i, ll head, ll prevSec){
    // head stores the node that's in the same level
    // as the node and it's ancestor
    ll curSection = sqrt(level[i]) + 1;
    if (curSection == 1){
        P[i] = 1;
    }
    else{
        if (curSection == prevSec + 1){
            P[i] = parent[i];
            head = i;
        }
        else P[i] = parent[head];
    }
    for (auto neigh : adjList[i]){
        if (neigh.first != parent[i])
            dfs_sqrt(neigh.first, head, curSection);
    }
}


ll lca_sqrt(ll u, ll v){
    while (P[u] != P[v]){
        if (level[u] > level[v])
            u = P[u];
        else v = P[v];
    }
    while(u != v){
        if(level[u] > level[v]){
            u = parent[u] ;
        }
        else{
            v = parent[v] ;
        }
    }
    return u ; //Either u or v store the lca.
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
        for (ll i = 0; i < MAX; i++)
            adjList[i].clear();

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
        bfs(root, 0, root, 0);
        dfs_sqrt(root, 1, 1);

        // cout << "\n dist are: \n";
        // for (int i = 1; i <= N; i++)
        //     cout << i << " : " << D[i] << " P: " << parent[i] << " L: " << level[i] << " P : " << P[i] <<  endl;

        ll num = 0, deno = 1;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++){
                if (i == j)
                    continue;
                ll _lca = lca_sqrt(sq[i], sq[j]);
                ll dA = abs(D[_lca] - D[sq[i]]);
                ll dB = abs(D[_lca] - D[sq[j]]);
                num += dA + dB;
                // find lca of sq[i] and sq[j]
            }
        }

        deno = M * M;
        ll _g = __gcd(num, deno);
        num /= _g, deno /= _g;
        printf("%lld %lld\n",num, deno);
    }
    return 0;
}
