#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned ll;

//You are given two fractions: 0/1 and 1/2. In each step, you will get two adjacent fractions 
// and you need to add them, if and only if, the denominator is equal to or smaller than the
//number obtained in that step and write it between those two adjacent fractions.

// Ofcoure I don't have a better algorithm than shifting as of now. Dumb Me :|

ll n, k;
const ll MAX = 100005;

vector<int> N;
vector<int> D;
ll _end = 1;

void addFractionsAndModifyArray(int step){
    int sz = N.size();
    for (int i = 0; i < sz; i++){        
        if (D[i] + D[i + 1] <= step ){
            int num = N[i] + N[i + 1];
            int deno = D[i] + D[i + 1];
            N.insert(N.begin() + i + 1, num);
            D.insert(D.begin() + i + 1, deno);
        }
    }
}

ostream & operator<<(ostream &c, vector<int> &T){
    for (auto t : T){
        c << t << " ";
    }
    return c;
}


int main(){
    cin >> n >> k;
    N.push_back(0);
    N.push_back(1);
    D.push_back(1);
    D.push_back(2);

    if (k == 0){
        cout << "0/1\n";
    }

    for (int i = 1; i <= n; i++){
        addFractionsAndModifyArray(i);
        // cout << "\n Step : " << i << "\n";
        // cout << N << "\n";
        // cout << D << "\n";
        // cout << "\n*********";
    }
    printf("%d/%d", N[k - 1],D[k - 1]);

    return 0;
}