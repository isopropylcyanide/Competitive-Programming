#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
vector<int> prime;
vector<int> primeLessThanN;

// There is a wall of size 4xN in the victim's house. The victim also has an infinite supply of bricks of size 4x1 and 1x4 in her house. There is a hidden safe which can only be opened by a particular configuration of bricks in the wall. In every configuration, the wall has to be completely covered using the bricks. There is a phone number written on a note in the safe which is of utmost importance in the murder case. Gale Bertram wants to know the total number of ways in which the bricks can be arranged on the wall so that a new configuration arises every time. He calls it M. Since Red John is back after a long time, he has also gained a masters degree in Mathematics from a reputed university. So, he wants Patrick to calculate the number of prime numbers (say P) up to M (i.e. <= M).

void sieveOfEratosthenes(){
    prime.resize(MAX, 1);
    primeLessThanN.resize(MAX);
    prime[1] = prime[0] = 0;
	int i = 2;
    while (i*i < MAX){
        if(prime[i] == 1)
          for(int j= i*i; j < MAX; j += i)
              prime[j] = 0;
        i +=1;
    }

    for (int i = 0, countPrime = 0; i < MAX; i++){
        if (prime[i])
            countPrime ++;
        primeLessThanN[i] = countPrime;
    }

}

int ways(int N){
    if (N < 4)
        return 1;

    vector<int> dp(N +1, 0);
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = 2;
    for(int i = 5; i <= N; i++)
        dp[i] = dp[i -1] + dp[i -4];

    return dp[N];
}

int main(){
    sieveOfEratosthenes();

    int N, testcases, ans;
    cin >> testcases;

    while(testcases --){
        cin >> N;
        ans = ways(N);
        cout << primeLessThanN[ans] << endl;
    }

    return 0;
}
