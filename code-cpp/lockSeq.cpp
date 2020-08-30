#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
ll N;

#define mod 1000000007

vector<ll> P = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0};
ll dp[100005][10];

ll f(ll i, ll last){
    ll ans = dp[i][last];
    if (ans != -1)
        return ans;
    ans = 0;
    if (i == N)
        ans = 1;
    else{
        for (ll dig = 0; dig < 10; dig++){
            if (i == 0)
                ans = (ans + f(i + 1, dig)) % mod;
            else if (!P[dig + last])
                ans = (ans + f(i + 1, dig)) % mod;
        }
    }
    dp[i][last] = ans % mod;
    return ans;
}



int main(){
    memset(dp, -1, sizeof(dp));
    cin >> N;
    cout << f(0, 0) << endl;

    return 0;
}
