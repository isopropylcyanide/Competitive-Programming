#include <bits/stdc++.h>
using namespace std;

int N, l, r;
// find the maxm value of function in range l - r

double f(double x){
    return 2*x*x - 12*x + 7;
}

double searchMax(int start, int end){
    // Find the maxm x for {start, end}
    double l = start, r = end;

    for (int i = 0; i < 200; i++){
        double l1 = (2*l + r)/ 3;
        double l2 = (l + 2*r)/ 3;
        // cout << "\n l1 : " << l1 << " l2: " << l2;
        double a = f(l1), b = f(l2);
        // cout << "\n f(l1) : " << a << " f(l2): " << b;
        if (a > b)
            l = l1;
        else r = l2;
    }
    // cout << "\n At the end: l: " << l << endl;
    return f(l);
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> l >> r;
        double ans = searchMax(l, r);
        cout << fixed << setprecision(0) << ans << endl;
    }
}
