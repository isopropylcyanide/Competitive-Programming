#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define N_MAX 10005
#define K_MAX 11
#define A_MAX 2
typedef long long ll;


ll T, N, K;
ll dp[N_MAX][A_MAX][K_MAX];

ll solver(ll i, ll tight, ll consec){
    // i is the current index we are on
    // tight: 1 if R = 1 0 otherwise
    // consec = number of consec rotten apples that can be placed
    ll ans = dp[i][tight][consec];
    if (ans != -1)
        return ans;

    ans = 0;
    if (i == N -1){
        // last apple
        if (tight)
            ans = 0;
        else ans = 1;
    }

    else if (tight == 0){
        // We are at an F
        ans = (ans + solver(i + 1, 0, K)) % MOD;
        ans = (ans + solver(i + 1, 1, consec -1)) % MOD;
    }
    else if (tight == 1){
        if (consec == 0)
            return 0;
        ans = (ans + solver(i + 1, 0, K)) % MOD;
        ans = (ans + solver(i + 1, 1, consec -1)) % MOD;
    }
    dp[i][tight][consec] = ans % MOD;
    return ans;
}

int main(){
    ios :: sync_with_stdio(false);

    cin >> T;
    while (T--){
        cin >> N >> K;
        memset(dp, -1, sizeof(dp));
        ll ans = solver(0, 0, K) + solver(0, 1, K -1);
        cout << ans % MOD << endl;
    }

    return 0;
}
