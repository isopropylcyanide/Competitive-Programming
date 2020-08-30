#include <bits/stdc++.h>
using namespace std;
#define MAX 1000007
typedef  long long unsigned llu;

/*
Find out if number of distinct prime factors in the prime factorization of a number are prime
*/

vector<llu> prime;

void sieveMinPrime(){
    prime.resize(MAX, 1);
    prime[1] = 0, prime[0] = 0;

    for(llu i = 2; i * i < MAX; i++){
        if (prime[i] == 1){
            prime[i] = i;
            for (llu j = i * i; j < MAX; j+=i)
                prime[j] = i;
        }
    }
}

llu countPrimeFactors(llu a){
    if (prime[a] == a)
        return 1;
    set<llu>  uniquePrime;

    while (prime[a] > 0){
        uniquePrime.insert(prime[a]);
        a /= prime[a];
    }

    return uniquePrime.size();
}

int main(){
    ios:: sync_with_stdio(false);

    sieveMinPrime();
    llu T, A, B, _lcm;
    cin >> T;

    while (T --){
        cin >> A >> B;
        _lcm = (A * B) / __gcd(A, B);
        llu distinctFact =  countPrimeFactors(_lcm);
        if (prime[distinctFact] == distinctFact)
            cout << "Yes\n";
        else
            cout <<"No\n";
    }

}
