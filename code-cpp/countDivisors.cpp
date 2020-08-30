#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000007;
int sp[MAXN];
typedef long long LL;
vector<LL> primes;
typedef unsigned long long ll;

/*find the greatest number X which divides the sum of the count of divisors of A and B as well as divides the absolute difference of count of divisors of A and B.
*/

ll mulMod(ll a, ll b ,ll c){
    ll x = 0 , y =a%c;
    while(b>0){
        if(b&1) x= (x+y)%c;
        y =(y<<1)%c;
        b >>= 1;
    }
    return x;
}

ll pow(ll a,ll b ,ll c){

    ll x=1 , y =a ;
    while(b>0){
        if(b&1){
            x= mulMod(x,y,c);
        }
        y = mulMod(y,y,c);
        b >>= 1;
    }
    return x;
}

bool millar(ll p , int it){
    if(p < 2 || p % 2 ==0 )return false;
    if(p < 4 ) return true;
    ll s= p-1;
    while(s%2==0){
        s>>=1;
    }
    while(it -- ){

        ll a = rand()%(p-1) + 1,temp = s;
        ll mod =pow(a,temp,p);
        if(mod == -1 || mod == 1 )
            continue;
        while(temp  != p-1 && mod != p-1){
            mod = mulMod(mod,mod,p);
            temp<<=1;

        }
        if(mod != p-1)
            return false;

    }
    return true;
}

void sieve(){
    sp[0] = 1;
    sp[ 1] = 1;
    sp[2] = 0;
    for(int i = 4 ; i < MAXN ; i += 2)
        sp[i] = 0;
    primes.push_back(2);
    for(long i = 3 ; i < MAXN ; i += 2){
        if(sp[i]==0){
            primes.push_back(i);
            sp[i] = 0;
            for(LL j = i ; i * j < MAXN ; j += 2){
                 sp[i*j ]= 1;
            }
        }
    }
}

inline bool isPrime(LL N){
    return millar(N,18);
}


LL divisors(LL N){

    LL ans = 1;
    for(int i = 0; i < (int)primes.size() ; ++i){
         LL p = primes[i];
         if(p*p*p > N )
            break;
        LL count = 1;
        while(N % p ==0){
            N /= p;
            count ++;
        }
        ans =ans *count;
    }
    if(isPrime(N)){
        ans *= 2LL;
    }
    else{
        LL sq = sqrt(N);
        if(sq*sq == N && isPrime(sq))
            ans = ans *3;
        else if(N != 1){
            ans = ans *4;
        }
    }
    return ans;
}

int main(){
    sieve();
    int T;
    cin>>T;
    while(T--){
        LL A,B;
        scanf("%lld %lld ",&A,&B);
        LL d1 = divisors(A) ;
        LL d2 = divisors(B);

       printf("%lld\n",__gcd(d1 + d2 , abs( d2 -d1)));
    }
    return 0;
}
