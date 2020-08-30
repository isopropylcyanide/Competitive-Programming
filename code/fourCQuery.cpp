#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// Output the number of numbers in a range L - R whose sum of digits is a perfect square and which has atleast one recurring digit

#define gc getchar_unlocked

void scanint(ll &x){
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

vector<ll> s;
ll N, T, L, R;
ll dp[20][163][2];
ll sumMod9[163];

ll sumDigRec(ll k){
    ll mod = k % 9;
    if (mod == 0)
        return k == 0 ? 0 : 9;
    return mod;
}

ll f(ll i, ll sumD, ll tight){
    // i is the current dig, sumD is the current squareSum
    // tight: whether ith dig in string is equal to ith of s
    // rec: whether recurring digit has occured
    ll ans = dp[i][sumD][tight];
    if (ans != -1)
        return ans;
    ans = 0;
    if (i == N){
        if (sumMod9[sumD] == 7)
            ans = 1;
        else ans = 0;
    }
    else{
        if (tight == 1){
            for (ll dig = 0; dig <= s[i]; dig++){
                if (dig == s[i])
                    ans += f(i + 1, sumD + dig, 1);
                else
                    ans += f(i + 1, sumD + dig, 0);
            }
        }
        else
            for (ll dig = 0; dig < 10; dig++)
                ans += f(i + 1, sumD + dig, 0);
    }
    dp[i][sumD][tight] = ans;
    return ans;
}

ll solve(ll num){
    // Solves problem for range 1 - num
    if (num == -1)
        return 0;
    s.clear();
    while (num){
        s.push_back(num % 10);
        num /= 10;
    }
    memset(dp, -1, sizeof(dp));
    reverse(s.begin(), s.end());
    N = s.size();
    return f(0, 0, 1);
}

ll brute(ll L, ll R){
    ll w = 0;
    for (int i = L; i <= R; i++)
        if (sumDigRec(i) == 7)
            w ++;
    return w;
}

int main(){
    for (int i = 0; i < 163; i++)
        sumMod9[i] = sumDigRec(i);
    scanint(T);

    while (T--){
        scanint(L);
        scanint(R);
        // scanf("%lld %lld",&L, &R);
        printf("%lld\n",solve(R) - solve(L -1));
    }
    return 0;
}
