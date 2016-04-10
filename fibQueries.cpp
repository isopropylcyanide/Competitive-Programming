#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ll;

#define MOD 1000000007
int N, M, x, y, a, b, c, d;
vector<ll> A;

/**/
void fast_fib(ll n,ll ans[]){
    if(n == 0){
        ans[0] = 0;
        ans[1] = 1;
        return;
    }

    fast_fib((n/2),ans);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      /* F(2n) */
    d = (a*a + b*b) % MOD;  /* F(2n + 1) */
    if ( n % 2 == 0){
        ans[0] = c;
        ans[1] = d;
    }
    else{
        ans[0] = d;
        ans[1] = c+d;
    }
}
/**/

int main(){
    ll fibAns[2] = {0};
    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    A.resize(N);
    char query;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < M; i++){
        cin >> query >> x >> y;
        x --;

        if (query == 'C')//change array
            A[x] = y;

        else{ //find function
            y --;
            ll set_size = y - x + 1;
            ll ans = 0;
            ll pow_set_size = pow(2, set_size);
            
            for (ll count = 0; count < pow_set_size; count++){
                ll minAns = 0;
                for (ll j = 0; j < set_size; j++)
                    if (count & (1 << j))
                        minAns = (minAns + *(A.begin() + j + x)) % MOD;

                fast_fib(minAns, fibAns);
                ans = (ans + fibAns[0]) % MOD;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
