#include<bits/stdc++.h>
using namespace std;
#define MAXM 9800   //1200th prime : 9733

typedef long long unsigned llu;
stack <llu> s;
vector<llu> prime(MAXM, 1);

void sieveEratos(){

}


int main(){
    ios::sync_with_stdio(false);
    sieveEratos();

    llu n, q, temp, i;
    cin >> n >> q;
    vector<llu> A;

    for (int i = 0; i < n; i++){
        cin >> temp;
        A.push_back(temp);
    }


    return 0;
}

// END
