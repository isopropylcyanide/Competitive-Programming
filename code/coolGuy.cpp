#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef  long long unsigned llu;

llu N;
vector<llu> A;

llu f(llu a, llu b){
    llu minE = A[a];
    for (llu i = a; i <= b; i ++)
        if (A[i] < minE)
            minE = A[i];
    return minE;
}

void solve(){
    llu ans = 0;
    for (int a = 0; a < N; a ++)
        for (llu b = a; b < N; b ++)
            for(llu c = b + 1; c < N; c++)
                for (llu d = c; d < N; d ++)
                    ans = (ans + min(f(a, b), f(c, d)) % MOD);
    cout << ans << endl;
}

int main(){
    cin >> N;
    A.resize(N);

    for (llu i = 0; i < N; i++)
        cin >> A[i];

    solve();
    return 0;
}
