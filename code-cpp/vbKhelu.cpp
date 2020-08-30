#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// Output the number of numbers in a range L - R whose sum of digits is a perfect square and which has atleast one recurring digit
vector<ll> s;
ll N, T, L, R;
ll dp[14][975][2][1024][2];

#define gc getchar_unlocked

void scanint(ll &x){
    register ll c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

bool isPerfectSquare(ll x){
    ll root = sqrt(x);
    return x != 0 && root* root == x;
}

bool PS[976];

ll f(ll i, ll sumSq, ll tight, ll B, ll rec){
    // i is the current dig, sumSq is the current squareSum
    // tight: whether ith dig in string is equal to ith of s
    // rec: whether recurring digit has occured
    ll ans = dp[i][sumSq][tight][B][rec];
    if (ans != -1)
        return ans;
    ans = 0;
    if (i == N){
        if (rec && PS[sumSq])
            ans = 1;
        else ans = 0;
    }
    else{
        if (tight == 1){
            for (ll dig = 0; dig <= s[i]; dig++){
                if (i == 0 && dig == 0)
                    continue;

                if (dig == s[i]){
                    if ((B >> dig) & 1)
                        ans += f(i + 1, sumSq + dig*dig, 1, B, 1);
                    else
                        ans += f(i + 1, sumSq + dig*dig, 1, B | (1 << dig), rec);
                }
                else{
                    if ((B >> dig) & 1)
                        ans += f(i + 1, sumSq + dig*dig, 0, B, 1);
                    else
                        ans += f(i + 1, sumSq + dig*dig, 0, B | (1 << dig), rec);
                }
            }
        }
        else{
            for (ll dig = 0; dig < 10; dig++){
                // check if this digit has occured
                if ((B >> dig) & 1)
                    ans += f(i + 1, sumSq + dig*dig, 0, B, 1);
                else
                    ans += f(i + 1, sumSq + dig*dig, 0, B | (1 << dig), rec);
            }
        }
    }
    dp[i][sumSq][tight][B][rec] = ans;
    return ans;
}

ll solve(ll num){
    // Solves problem for range 1 - num
    s.clear();
    while (num){
        s.push_back(num % 10);
        num /= 10;
    }
    memset(dp, -1, sizeof(dp));
    reverse(s.begin(), s.end());
    N = s.size();
    return f(0, 0, 1, 0, 0);
}

int main(){
    for (ll i = 0; i < 976; i++)
        PS[i] = isPerfectSquare(i);
    scanint(T);

    while (T--){
        scanint(L);
        scanint(R);
        printf("%lld\n",solve(R) - solve(L -1));
    }


    return 0;
}
