#include <bits/stdc++.h>
using namespace std;

/* Program to find the lower bound and upper bound of a number in array
    e.g. 1, 2, 3, 3, 3, 3, 4, 4, 5, 6, 8, 8, 12
        LB(3) = 2, UB(3) = 7
*/
int _lowerbound(vector<int> &A, int l, int h, int x){
    int lb = INT_MAX;
    while  (l <= h){
        int m = l + (h - l)/2;

        if (A[m] == x){
            // then we found a lower bound. Now we may find others on our left
            if (m < lb)
                lb = m;
            h = m - 1;
        }
        else if (A[m] < x)
            l = m + 1;
        else
            h = m -1;
    }
    return lb == INT_MAX ? l : lb;
}

int _upperbound(vector<int> &A, int l, int h, int x){
    int ub = INT_MAX;
    while  (l <= h){
        int m = l + (h - l)/2;

        if (A[m] == x){
            // then upper bound exists to the right
            l = m + 1;
        }
        else if (A[m] > x){
            if (m < ub)
                ub = m;
            h = m - 1;
        }
        else
            l = m  + 1;
    }
    return ub == INT_MAX ? h + 1 : ub;
}


int main(){
    vector<int> A = {10, 10, 10, 20, 20, 20, 30};
    int n;

    for (int i = 0; i < A.size(); i++)
        cout << A[i] <<  "(" << i << ") : ";
    cout << endl;

    while (true){
        cout << "\n Enter a number \t";
        cin >> n;
        int i = _lowerbound(A, 0, A.size() -1, n);
        int j = _upperbound(A, 0, A.size() -1, n);
        int a = lower_bound(A.begin(), A.end(), n) - A.begin();
        int b = upper_bound(A.begin(), A.end(), n) - A.begin();
        cout << "\n c++ lower: " << a << " and upper: " << b << endl;
        cout << " my+ lower: " << i << " and upper: " << j << endl;
    }

}
