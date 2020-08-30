#include <bits/stdc++.h>
using namespace std;

#define MAX 100005
#define MOD 1000000007
typedef long long ll;

ll bit0[MAX], bit1[MAX], bitL[MAX];
//bit0[i] means a subsequence with i as the larger element in the end of subsequence
// bit1[i] is opposite of bit0[i] i.e with i as the lowest element

ll N;
vector<ll> A;

void update(ll B[], ll i, ll val){
    while(i < MAX){
        B[i] = (B[i] + val) % MOD;
        i += (i & -i);
    }
}

ll query(ll B[], ll i){
    ll ans = 0;
    while(i > 0){
        ans = (ans + B[i]) % MOD;
        i -= (i & -i);
    }
    return ans;
}


int main(){
    cin >> N;
    A.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    ll ans = 0;
    for(ll i = 0; i < N; ++i){
        ll Ai_is_small, Ai_is_big;
        Ai_is_big = (query(bit1, A[i]-1) + query(bitL, A[i]-1)) % MOD;
        Ai_is_small = ((query(bit0, MAX) - query(bit0,A[i])) % MOD + ((query(bitL, MAX)) - query(bitL, A[i])) % MOD) %MOD;
        if(Ai_is_small < 0)
            Ai_is_small += MOD;
        ans = (ans + Ai_is_big + Ai_is_small) % MOD;

        update(bitL, A[i], 1);
        update(bit0, A[i], Ai_is_big);
        update(bit1, A[i], Ai_is_small);
    }
    cout << ans << endl;

    return 0;
}
