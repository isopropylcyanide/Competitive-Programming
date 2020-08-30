#include <bits/stdc++.h>
using namespace std;

int main(){
    // Program to calculate factorials of very large numbers in C++
    vector<int> F(200, 0);
    int test, n, m, temp, x;

    cin >> test;
    while (test --){
        cin >> n;
        F[0] = 1;
        m = 1;

        temp = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < m; j++){

                x = F[j] * i + temp;
                F[j] = x % 10;
                temp = x/10;
            }
            while (temp){
                F[m] = temp % 10;
                temp /= 10;
                m++;
            }
            cout << "\n Stage i: " << i << endl;
            for (auto a : F)
                cout << a;
            cout << endl;
        }

        for (int i = m -1; i >= 0; i--)
            cout << F[i];
            cout << endl;
    }

        return 0;
}
