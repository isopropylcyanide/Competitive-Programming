#include <bits/stdc++.h>
using namespace std;

// Sparse table for range minimum query
// Preproces :: O(NlogN)
// Query RMQ :: O(1)
vector<vector<int> > T; //table

void preprocess(vector<int> &A){
    int N = A.size();
    int M = int(ceil(log(N))) + 1;
    T.resize(N, vector<int>(M, -1));

    //Table is filled column wise
    for (int j = 0; j < M; j++){
        for (int i = 0; i + pow(2, j) - 1 < N; i++){
            if (j == 0)
                T[i][j] = i;
            else{
                //break into powerers of 2
                int low = T[i][j -1];
                int high = T[i + pow(2, j -1)][j -1];
                if (A[low] < A[high])
                    T[i][j] = low;
                else
                    T[i][j] = high;
            }
        }
    }
}

int query(int a, int b, vector<int> &A){
    int num = b - a + 1;
    int k = log(num);
    int l = T[a][k], r = T[num + a - (1 << k)][k];
    return min(A[l], A[r]);

}

int main(){

    vector<int> A{4, 6, 1, 5, 7, 3};
    for (auto a : A)
        cout << a << " ";
    cout << endl;

    preprocess(A);
    int a, b;
    while (true){
        cout << "\n Find min between a - b inclusive\t";
        cin >> a >> b;
        cout << query(a, b, A) << endl;
    }



}
