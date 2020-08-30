#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define MAX 100005
typedef long long ll;

typedef pair<ll, ll> pii;
ll res = 0;

ll N, K, a, b;
vector<ll> adj[MAX];
ll A[MAX], dp[1 << 21];

void dfs(ll i, ll par, ll _xor){
    // Traverse tree and store level and parents
    _xor ^= A[i];
    res += dp[_xor ^ K];
    dp[_xor]++;

    for (auto neigh : adj[i]){
        if (neigh != par)
            dfs(neigh, i, _xor);
    }
    dp[_xor]--;
}

int main(){
    cin >> N >> K;

    for (ll i = 1; i <= N; i++)
        cin >> A[i];

    for (ll i = 1; i < N; i++){
        cin >> b;
        a = i + 1;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    dp[0] = 1;
    dfs(1, 1, 0);
    cout << res<< "\n";

    return 0;
}
