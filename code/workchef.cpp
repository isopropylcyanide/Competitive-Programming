#include<bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
#define MAX 1000005
/*calculate number of K-special numbers in the range [L, R] (i.e. L, L + 1, L + 2, ..., R).
A number X is said to be K-special if there exist K or more different digits, such that X is divisible by those digits and those digits are present in the decimal representation of the number. For example, number 48 is both 1 and 2 special, as it is divisible by digits 4 and 8. Note that no positive integer is divisible by number 0.*/

ll L, R, K, Q, N;
string str;

ll dp[19][2][512][2521];
ll modul[25200];

ll f(ll i, ll tight, ll bits, ll curMod){
    // i: cur digit, special: curSpeciality
    // store modulus of num % each digit
    ll ans = dp[i][tight][bits][curMod];

    if (ans != -1)
        return ans;
    ans = 0;
    if (i == N){
        ll special = 0;
        if (bits == 0)
            ans = 0;
        else for (int j = 1; j <= 9; j++){
            if ((curMod % j) == 0 && (bits & 1 << (j -1)))
                special ++;
        }
        if (special >= K)
            ans = 1;
        else ans = 0;
    }

    else if (tight == 1){
        // we are at the boundary dig
        for (int dig = 0; dig <= str[i] - '0'; dig++){
            if (dig == str[i] - '0'){
                if (dig == 0)
                    ans = (ans + f(i + 1, 1, bits, modul[curMod *10 + dig]));
                else ans = (ans + f(i + 1, 1, bits | (1 << (dig -1)), modul[curMod *10 + dig]));
            }
            else{
                if (dig == 0)
                    ans = (ans + f(i + 1, 0, bits, modul[curMod *10 + dig]));
                else ans = (ans + f(i + 1, 0, bits | (1 << (dig -1)), modul[curMod *10 + dig]));
            }
        }
    }
    else{
        for (int dig = 0; dig <= 9; dig++){
            if (dig == 0)
                ans = (ans + f(i + 1, 0, bits, modul[curMod *10 + dig]));
            else ans = (ans + f(i + 1, 0, bits | (1 << (dig -1)), modul[curMod *10 + dig]));
        }

    }
    dp[i][tight][bits][curMod] = ans;
    return ans;
}


ll solve(ll num){
    str = to_string(num);
    N = str.size();

    memset(dp, -1, sizeof(dp));
    return f(0, 1, 0, 0);
}


int main(){
    for (int i = 0; i < 25200; i++)
        modul[i] = i % 2520;

    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> Q;
    ll num = 0;

    while (Q--){
        cin >> L >> R >> K;
        num = solve(R) - solve(L -1);
        cout << num << endl;
    }

    return 0;
}
