#include <bits/stdc++.h>
using namespace std;

/*
Find number of numbers consisting of N digits, that have value > 0 and
are divisible by M. Also their sum of squares of digits should be divisible by M.

Constraint is there are k pairs..each consisting of two digits from 0-9
Eliminate all numbers in which a and b appear adjacent to each other
She gives you X pairs of numbers, each pair consists of 2 numbers from 1 to 9.
Given these pairs , assume one of them to be consisting of numbers a and b,
eliminate out all numbers in which a and b appear adjacent to each other
*/

typedef long long ll;
ll N, M, k, a, b;

#define MOD 1000000007

ll adj[10][10];
//adj[i][j] = 1 if i and j digits are adjacent

ll dp[1001][21][21][11];

ll f(ll i, ll mod, ll sqMod, ll lastDigit){
    // i: current digit, mod: current mod
    ll ans = dp[i][mod][sqMod][lastDigit];
    if (ans != -1)
        return ans;

    ans = 0;
    if (i == N)
        ans = (mod == 0 && sqMod == 0) ? 1 : 0;

    else{
        for (ll dig = 0; dig <= 9; dig++){
            // skip 0
            if (i == 0 && dig == 0)
                continue;
            // if first digit then no lastDigit
            else if (i == 0)
                ans = (ans + f(i + 1, dig % M, (dig*dig) % M, dig)) % MOD;
            //else check if curDig and last aren't adjacent
            else if (!adj[lastDigit][dig])
                ans = (ans + f(i + 1, (mod * 10 + dig) % M, (sqMod + dig*dig) % M, dig)) % MOD;
        }
    }
    dp[i][mod][sqMod][lastDigit] = ans;
    return ans;
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> k;
    for (int i = 0; i < k; i++){
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0, 0, 0) << endl;
}
