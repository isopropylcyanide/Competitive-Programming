#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> S; //the sum 2D matrix

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &A) {
        //Preprocess matrix S to get the running sum in O(1)

        int n = A.size();
        if (n == 0)
            return;
        int m = A[0].size();
        S.resize(n, vi(m, 0));
        S[0][0] = A[0][0];

        for (int j = 1; j < m; j++)
            S[0][j] = S[0][j -1] + A[0][j];

        for (int i = 1; i < n; i++)
            S[i][0] = S[i -1][0] + A[i][0];

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                S[i][j] = S[i -1][j] + S[i][j -1] - S[i -1][j -1] + A[i][j];

    }

    int sumRegion(int x1, int y1, int x2, int y2) {
        //Using the preprocessed matrix, find the sum of [x1][y1] to [x2][y2]
        if (S.size() == 0 || S[0].size() == 0)
            return 0;
        if (x1 == 0 && y1 == 0)
            return S[x2][y2];
        else if (x1 == 0)
            return S[x2][y2] - S[x2][y1 - 1];
        else if (y1 == 0)
            return S[x2][y2] - S[x1 -1][y2];
        else
            return S[x2][y2] - S[x1 -1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
    }
};

int main(){
    vector< vector<int> > matrix = {
          {3, 0, 1, 4, 2},
          {5, 6, 3, 2, 1},
          {1, 2, 0, 1, 5},
          {4, 1, 0, 1, 7},
          {1, 0, 3, 0, 5}
    };

    NumMatrix n(matrix);
    cout << n.sumRegion(2, 1, 4, 3) << endl;
    cout << n.sumRegion(1, 1, 2, 2) << endl;
    cout << n.sumRegion(1, 2, 2, 4) << endl;
}
