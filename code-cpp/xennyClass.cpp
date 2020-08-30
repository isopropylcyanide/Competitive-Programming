#include <bits/stdc++.h>
using namespace std;

string populate(int N, int tog){
    //Populate string starting from B/G first
    string s = "";
    for (int i = 0; i < 2*N; i++){
        if (tog == 0)
        s += 'B';
        else s += 'G';
        tog ^= 1;
    }
    return s;
}

int minSwaps(int N, string &s){
    // Let B = 0, G = 1
    string a = populate(N, 0);
    string b = populate(N, 1);

    int cA = 0, cB = 0;

    for (int i = 0; i < 2*N; i++){
        if (s[i] != a[i])
            cA ++;
        else if (s[i] != b[i])
            cB ++;
    }
    return min(cA/2, cB/2);
}

int main(){

    int testcases, N;
    cin >> testcases;
    string s;

    while (testcases --){
        cin >> N;
        cin >> s;
        cout << minSwaps(N, s) << endl;
    }


    return 0;
}
