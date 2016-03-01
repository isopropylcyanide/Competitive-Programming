#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000010
vector<int> prime;

void precompute(){
    prime.resize(MAX, 1);
    prime[1] = prime[0] = 0;
	int i = 2;

    while (i*i < MAX){
        if(prime[i] == 1)
          for(int j = i*i; j < MAX; j += i)
              prime[j] = 0;
        i += 1;
    }
}

int main() {
    precompute();
    int testcases, N;
    cin >> testcases;
    while (testcases --){
        cin >> N;
        int l = N - 1, r = N + 1, ans;

        if (prime[N]){
            cout << N << endl;
            continue;
        }
        while (l > 0 and r < MAX){
            if (prime[l] && prime[r]){
                ans = l < r ? l : r;
                break;
            }
            if (prime[l]){
                ans = l;
                break;
            }
            if (prime[r]){
                ans = r;
                break;
            }
            l --;
            r ++;
        }
        cout << ans << endl;
    }

    return 0;
}
