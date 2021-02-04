#include <bits/stdc++.h>

template <typename T>
ostream &operator<<(ostream &c, vector<T> &vec) {
    for (auto t : vec) {
        c << t << ' ';
    }
    return c;
}

template <typename T>
ostream &operator<<(ostream &c, vector<vector<T>> &vec) {
    for (auto t : vec) {
        c << t << ' ';
        c << std::endl;
    }
    return c;
}

int numSubmat(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int numAllSquaresOne = 0;

    //prepare prefix arrays
    for (int i = 0; i < n; i++) {
        int last = 0;
        for (int j = m - 2; j >= 0; j--) {
            if (mat[i][j] == 1) {
                mat[i][j] += mat[i][j + 1];
            }
        }
    }
    std::cout << mat;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //figure out combinations of rectangles ending at this node
            if (mat[i][j] == 0) {
                continue;
            }
            int minWidth = mat[i][j];
            for (int height = i; height < n; height++) {
                if (mat[height][j] == 0) {
                    //no rectangle possible if this submatrix is pivoted at a 0
                    break;
                }
                minWidth = min(minWidth, mat[height][j]);
                numAllSquaresOne += minWidth;
            }
        }
    }
    return numAllSquaresOne;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<vector<int>> m = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};

    std::cout << numSubmat(m);
    return 0;
}
