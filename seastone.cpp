#include <bits/stdc++.h>
using namespace std;

#define MAXN 78000

typedef long long ll;


ll INF = LLONG_MAX;
ll T, N, M, ans;
ll A[MAXN], P[MAXN];
map <pair<ll, ll>, ll > dp;

ll f(ll box, ll stones){
    if (stones == 0 || box <= 1 || stones % box == 0)
        return 0;
    if (dp.count({box, stones}))
        return dp[{box, stones}];
    ll ans = INF;
    for (ll i = 1; i <= min(stones, box); i++){
        if (box - i - 1 >= 0 && stones % i < stones /i)
            ans = min(ans, P[box -i -1 ] *i + f(box - i, stones % i));
    }

    dp[{box, stones}] = ans;
    return ans;
}

int main(){
   scanf("%lld", &T);

   while(T--){

       scanf("%lld %lld", &N, &M);
       for (int i = 0; i < N; i++)
            scanf("%lld", &A[i]);

       sort(A, A + N);
       P[0] = A[0];

       for (int i = 1; i <= N - 1; i++)
          P[i] = P[i-1] + A[i];

       dp.clear();

       printf("%lld\n", f(N, M));
   }
   return 0;
}
