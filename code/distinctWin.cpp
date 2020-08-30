#include <bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &A, int K) {
    int N = A.size();
    vector<int> ans;
    map<int, int> M;

    for(int i = 0; i < N; i++){
        M[A[i]] += 1;
        if (i - K + 1 >= 0){
            ans.push_back(M.size());
            M[A[i - K +1]] -= 1;

            if (M[A[i - K +1]] == 0)
                M.erase(A[i - K +1]);
        }
    }
    return ans;
}


int main(){
    int N, K;
    cin >> N;
    vector <int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> K;

    for (auto a : dNums(A, K))
        cout << a << " -> ";
    return 0;
}
