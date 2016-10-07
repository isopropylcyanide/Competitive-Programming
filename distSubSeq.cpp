#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define MAX 100005

int t, n;
string s;
int last[255];

int dp[MAX];

int main(){
    cin >> t;
    while (t--){
        memset(dp, 0, MAX);
        memset(last, -1, sizeof(last));
        cin >> s;
        n = s.size();

        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            dp[i] = (dp[i -1] * 2) % mod;

            if (last[s[i -1]] != -1)
            dp[i] = (dp[i] - dp[last[s[i -1]]] + mod) % mod;

            last[s[i -1]] = i -1;
        }
        cout << dp[n] << endl;
    }
    return 0;
}
