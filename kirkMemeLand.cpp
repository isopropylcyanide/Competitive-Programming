#include <bits/stdc++.h>
using namespace std;

#define MAX 50001
typedef long long ll;

vector<vector<ll> > adjList;
ll parent[MAX], ht[MAX], peak[MAX];
/*
Key logic: Every node stores the number of nodes that are present in sq array and
are in its subtree. When removing an edge, remove the one which is at the lowest level
*/

ll T, N, M, u, v, L, R;
ll root, temp, _count;

inline ll peaksInArray(vector<ll> &A){
    ll n = A.size(), peaks = 0;
    for (ll i = 1; i < n- 1; i++){
        if (A[i] > A[i -1] && A[i] > A[i + 1])
            peaks += 1;
    }
    return peaks;
}

ostream &operator <<(ostream &c, vector<ll> &V){
    for (auto k : V)
        cout << k << " : ";
    return c;
}


void  dfs(ll i, ll par, vector<ll> &cur, ll &_count){
    parent[i] = par;
    // cout << "\n\n for i: " << i << " cur : " << cur;
    ll numPeaks = 0;

    for (auto neigh : adjList[i]){
        if (neigh != par){
            cur.push_back(ht[neigh]);
            dfs(neigh, i, cur, _count);
            cur.pop_back();
        }
    }
    // cout << "\ni: " << i << " vec: " << cur;
    numPeaks = peaksInArray(cur);
    // cout << "\n peaks: " << numPeaks << endl;
    if (numPeaks >= L && numPeaks <= R)
        _count += 1;
}



int main(){
    scanf("%lld", &T);

    while(T--){
        scanf("%lld",  &N);
        scanf("%lld %lld",&L, &R);

        for (ll i = 1; i <= N; i++)
            scanf("%lld", &ht[i]);

        adjList.resize(MAX);
        for (ll i = 0; i < MAX; i++)
            adjList[i].clear();


        for (ll i = 0; i < N -1; i++){
            scanf("%lld %lld",&u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        memset(parent, MAX, 0);
        memset(peak, MAX, 0);

        ll sumRoot = 0;
        // find root of the tree. root is the one which has only one edge
        for (ll root = 1; root <= N; root++){
            vector<ll> cur;
            cur.push_back(ht[root]);
            _count = 0;
            dfs(root, 0, cur, _count);
            sumRoot += _count;
            // cout << "\n For tree rooted at " << root << " : " << _count;
        }
        printf("%lld\n", sumRoot/2);
    }


    return 0;
}
