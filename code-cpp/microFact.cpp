#include <bits/stdc++.h>
using namespace std;
typedef long long int llu;

// There is a wall of size 4xN in the victim's house. The victim also has an infinite supply of bricks of size 4x1 and 1x4 in her house. There is a hidden safe which can only be opened by a particular configuration of bricks in the wall. In every configuration, the wall has to be completely covered using the bricks. There is a phone number written on a note in the safe which is of utmost importance in the murder case. Gale Bertram wants to know the total number of ways in which the bricks can be arranged on the wall so that a new configuration arises every time. He calls it M. Since Red John is back after a long time, he has also gained a masters degree in Mathematics from a reputed university. So, he wants Patrick to calculate the number of prime numbers (say P) up to M (i.e. <= M).

#define MAX 100005
vector<int> prime;

void sieveOfEratosthenes(){
    prime.resize(MAX, 1);
    prime[1] = prime[0] = 0;
	llu i = 2;

    while (i*i < MAX){
        if(prime[i] == 1)
          for(llu j= i*i; j < MAX; j += i)
              prime[j] = 0;
        i +=1;
    }

}


llu primePowerinFact(llu n, llu p){
    llu total = 0;
    llu limit = (llu)(log(n) / log(p)) + 1;
    for (llu i = 1; i <= limit; i++){
        total += (llu)(n / pow(p, i));
    }
    return total;
}

int main() {
    sieveOfEratosthenes();
    int testcases, X, Y;
    cin >> testcases;
    while (testcases --){
        cin >> X >> Y;

        llu totalX = 1;
        for (int i = 2; i < X + 1; i++){
            llu newT = 0;
            if (prime[i]){
                // cout <<"Power of "<<i<<" in X!: "<<primePowerinFact(X, i) << endl;
                newT += primePowerinFact(X, i);
            }
            totalX = ((totalX ) * (newT + 1)) % MOD;
        }

        llu totalY = 1;
        for (int i = 2; i < Y + 1; i++){
            llu newT = 0;
            if (prime[i]){
                // cout <<"Power of "<<i<<" in Y!: "<<primePowerinFact(Y, i) << endl;
                newT += primePowerinFact(Y, i);
            }
            totalY = ((totalY ) * (newT + 1)) % MOD;
        }
        // cout <<"\ntotalX : "<<totalX;
        // cout <<"\ntotalY : "<<totalY<<endl;
        cout <<( abs(totalX - totalY) + MOD)% MOD << endl;
    }

    return 0;
}
