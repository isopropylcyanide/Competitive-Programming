#include<bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;
#define MAX 1000005
/*calculate number of K-special numbers in the range [L, R] (i.e. L, L + 1, L + 2, ..., R).
A number X is said to be K-special if there exist K or more different digits, such that X is divisible by those digits and those digits are present in the decimal representation of the number. For example, number 48 is both 1 and 2 special, as it is divisible by digits 4 and 8. Note that no positive integer is divisible by number 0.*/

ll L, R, K, Q;
ll P[MAX];

int getSpecial(ll N){
    //returns the maximum speciality of a number
    set<int> S;
    ll _N = N;
    int spec = 0;

    while (_N){
        S.insert(_N % 10);
        _N /= 10;
    }
    S.erase(0);
    for (auto a : S)
        if (N % a == 0)
            spec += 1;
    return spec;
}

inline void precompute(){
    //Precompute special matrix
    for (int i = 0; i < MAX; i++)
        P[i] = getSpecial(i);
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    cin >> Q;
    ll num;

    for (int i = 1; i <= 100; i++)
        cout << P[i] << " ";
    while (Q--){
        cin >> L >> R >> K;
        num = 0;

        for (int i = L; i <= R; i++){
            if (P[i] >= K)
                num ++;
        }
        cout << num << endl;
    }

    return 0;
}
