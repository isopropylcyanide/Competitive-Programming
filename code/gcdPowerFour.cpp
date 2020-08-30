#include<bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;

#define MAX 100001 
const ll MOD = 1e9 + 7;

ll T;
ll N, k;

// phi[i] stores euler totient function for i 
// result[j] stores result for value j 
long long phi[MAX], result[MAX]; 
  
void computeTotient() { 
    phi[1] = 1; 
    for (int i = 2; i < MAX; i++) { 
        if (!phi[i]) { 
            phi[i] = i - 1; 
            for (int j = (i << 1); j < MAX; j += i) { 
                if (!phi[j]) 
                    phi[j] = j; 
                phi[j] = (phi[j] / i) * (i - 1); 
            } 
        } 
    } 
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    computeTotient();
    for (int i = 0; i < 20; i++){
        cout << "For " << i << " : " << phi[i] << "\n";
    }
    cin >> T;

    while (T--){
        cin >> N;
    }

    return 0;
}