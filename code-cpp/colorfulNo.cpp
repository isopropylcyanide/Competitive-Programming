#include <bits/stdc++.h>
using namespace std;


int colorful(int N) {
    vector<int> A;
    while (N > 0){
        A.push_back(N % 10);
        N /= 10;
    }
    reverse(A.begin(), A.end());

    set<int> s;
    for (int i = 0; i < A.size(); i++){
        for (int j = i; j < A.size(); j++){
            int num = 1;
            for (int k = i; k <= j; k++)
                num *= A[k];
            // cout << " Num: "<< num << endl;
            if (s.find(num) != s.end())

                return 0;
            s.insert(num);
        }
    }

    return 1;
}


int main(){
    int A;
    cin >> A;
    cout << colorful(A);
}
