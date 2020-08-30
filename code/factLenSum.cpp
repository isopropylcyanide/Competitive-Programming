#include <bits/stdc++.h>
using namespace std;
typedef long long int llu;

#define MAX (1e6 + 5)
llu N, Q,  totalMoves;
vector<int> prime;
vector<int> A;
vector<int> sumPrime;
vector<bool> V;

void sieveOfEratosthenes(){
        // Find minimum prime
        prime.resize(MAX);
        sumPrime.resize(MAX);
        V.resize(MAX);

        for (llu i = 2; i < MAX; i +=2)
                prime[i] = 2;

        for (llu i = 3; i < MAX; i +=2)
                if (!V[i]) {
                        prime[i] = i;
                        for (llu j = i; (j*i) < MAX; j += 2) {
                                if (!V[j*i]) {
                                        V[j*i] = true;
                                        prime[j*i] = i;
                                }
                        }
                }
        // Also store the sum of all prime powers in a vector
        for (llu j = 0; j < MAX; j++){
            llu total = 0, i = j;
            while (prime[i] > 0){
                total += 1;
                i /= prime[i];
            }
            sumPrime[j] = total;
        }
}



inline llu factorize(llu n){
        // Add prime powers for n, n-1, n-2 .. 1
        llu primeSum = 0;
        for (llu i = n; i >= 0; i--)
            primeSum += sumPrime[i];

        return primeSum;
}


int main(){
        ios :: sync_with_stdio(false);
        sieveOfEratosthenes();
        cin >> N;
        A.resize(N);

        for(llu i = 0; i < N; i++)
            cin >> A[i];

        llu evenSum = 0;
        vector<int> cached(N, 0);

        for(llu i = 0; i < N; i++)
            cached[i] = factorize(A[i]);

        llu pow_set_size = pow(2, N);
        llu counter, j;

        for(counter = 0; counter < pow_set_size; counter++){
            llu mySum = 0;
            for(j = 0; j < N; j++){
                if(counter & (1<<j)){
                    mySum += cached[j];
                }
            }
            if (mySum % 2 == 0)
                evenSum += mySum;
        }

        cout << evenSum<<endl;
        return 0;
}























//
