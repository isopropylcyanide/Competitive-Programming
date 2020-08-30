#include <bits/stdc++.h>
using namespace std;

//How many minimum numbers from fibonacci series are required such that sum of numbers be equal to a given Number N?
typedef long long unsigned ll;
vector<ll> A;

void precompute(){
    //Store the first fibs < LONG_MAX
    A.clear();
    A.push_back(1);
    A.push_back(1);
    for (int i = 2; A[i -1] < LONG_MAX; i++)
        A.push_back(A[i -1] + A[i -2]);
}

int minCoinsDP(int N){
    //Minimum coins to change N given M coins
    vector<int> T(N + 1, INT_MAX);
    T[0] = 0;

    for (int i = 1; i <= N; i++){
        for (int j = 0; j < A.size(); j++)
            if (A[j] <= i){
                int left = T[i - A[j]];
                if (left != INT_MAX && left + 1 < T[i])
                    T[i] = left + 1;
            }
    }
    return T[N];
}

int minCoinsGreedy(int N){
    //Minimum coins to change N given M coins
    int minCoins = 0;
    for (int i = A.size() -1; i >= 0; i--){
        while (N >= A[i]){
            N -= A[i];
            minCoins += 1;
        }
    }
    return minCoins;
}

int fibsum(int N) {
    precompute();
    return minCoinsGreedy(N);
}


int main(int argc, char **argv){
    cout << fibsum(atoi(argv[1])) << endl;
    return 0;
}
