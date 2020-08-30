#include<bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;

#define MAX 1000005 
const ll MOD = 1e9 + 7;
int sp[MAX], isPrime[MAX];
vector<ll> primes;

ll T;
ll N, k;

// phi[i] stores euler totient function for i 
long long phi[MAX], divs[MAX]; 
  
void computeTotient() { 
    phi[1] = 1; 
    for (int i = 2; i < MAX; i++) { 
        if (!phi[i]) { 
            phi[i] = i - 1; 
            for (int j = (i << 1); j < MAX; j += i) { 
                if (!phi[j]) {
                    phi[j] = j; 
                }
                phi[j] = (phi[j] / i) * (i - 1); 
            } 
        } 
    } 
} 

void sieve(){
    sp[0] = 1;
    sp[ 1] = 1;
    sp[2] = 0;
    for(int i = 4 ; i < MAX ; i += 2){
        sp[i] = 0;
        isPrime[i] = 0;
    }
    primes.push_back(2);
    for(long i = 3 ; i < MAX ; i += 2){
        if(sp[i]==0){
            isPrime[i] = 1;
            primes.push_back(i);
            sp[i] = 0;
            for(ll j = i ; i * j < MAX ; j += 2){
                 sp[i*j ]= 1;
            }
        }
    }
}

ll divisors(ll N){

    ll ans = 1;
    for(int i = 0; i < (int)primes.size() ; ++i){
         ll p = primes[i];
         if(p*p*p > N )
            break;
        ll count = 1;
        while(N % p ==0){
            N /= p;
            count ++;
        }
        ans =ans *count;
    }
    if(isPrime[N] == 1){
        ans *= 2ll;
    }
    else{
        ll sq = sqrt(N);
        if(sq*sq == N && (isPrime[sq] ==1))
            ans = ans *3;
        else if(N != 1){
            ans = ans *4;
        }
    }
    return ans;
}

void preComputeDivisors(){
    divs[0] = 0;
    divs[1] = 1;
    for (ll i = 2; i <= MAX; i++){
        divs[i] = divisors(i);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    computeTotient();
    preComputeDivisors();
    // for(int i = 0; i < (int)primes.size() ; ++i){
    //     if
    // }
    for (int i = 0; i < 20; i++){
        cout << "For " << i << " : num gcd 1 = " << phi[i] << " and divs " << divs[i] << "\n";
    }
    cin >> T;

    while (T--){
        cin >> N;
        int numWithGCD1WithN = N - phi[N];
        int numWithGCDNWithN = divs[N];
        cout << numWithGCD1WithN - (numWithGCDNWithN - 1) << "\n";
    }

    return 0;
}