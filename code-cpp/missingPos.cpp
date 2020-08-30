#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int firstMissingPositive(vector<int> &);
};


int Solution::firstMissingPositive(vector<int> &A) {
    // Partition array into positive and negative half
    int j = -1;
    for (int i = 0; i < A.size(); i++){
        if (A[i] <= 0){
            j++;
            swap(A[i], A[j]);
        }
    }
    A.erase(A.begin(), A.begin() +j);
    for(int i = 0; i < A.size(); i++){
        if (abs(A[i]) -1 < A.size() && A[abs(A[i]) -1] > 0)
            A[abs(A[i]) -1] = -A[abs(A[i]) -1];
    }
    for (int i = 0; i < A.size(); i++){
        if (A[i] > 0)
            return i +1;
    }
    return A.size() +1;
}




int main(){
    int N, T;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i ++)
        cin >> A[i];

    Solution a;
    cout << a.firstMissingPositive(A);
    return 0;
}






//
