
#include<bits/stdc++.h>
using namespace std;

int A[105];

int main(){
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> t;
        A[t]++;
    }
    int ways = 0;
    for (int i = 0; i < 100; i++)
        ways += A[i]/2;
    cout << ways << endl;
    return 0;
}
