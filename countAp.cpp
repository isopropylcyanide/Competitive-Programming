#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009

typedef long long ll;

int main(){
    ll n;
    scanf("%lld", &n);
    ll a[n + 1];
    for(ll i = 1; i <= n; i++)
    scanf("%lld", &a[i]);

    ll ans = 0;
    ll dp[n + 1];

    memset(dp, 0, n + 1);
    for(ll diff = -100; diff <= 100; diff++){
        ll sum[101], cur=0;
        memset(sum, 0, sizeof(sum));

        for(ll i = 1; i <= n; i++){
            dp[i] = 1;
            if(a[i] - diff >= 1 && a[i] - diff <= 100)
                dp[i] = (sum[a[i] - diff] + dp[i]);

            sum[a[i]] = (sum[a[i]] + dp[i]) % MOD;
            cur = (cur + dp[i]) % MOD;
        }
        // cur = (cur - n)%MOD;
        ans = (ans + cur) % MOD;
        ans = (ans - n + MOD) % MOD;
    }
    ans = (ans + n) % MOD;
    cout << ans+1 << "\n";
    return 0;
}
