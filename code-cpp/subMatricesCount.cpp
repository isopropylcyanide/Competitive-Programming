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
    vector<vector<int>> rowOnes(n, vector<int>(m, 0));
    vector<vector<int>> colOnes(n, vector<int>(m, 0));

    //prepare prefix arrays
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                rowOnes[i][j] = ((mat[i][j] == 1) ? 1 : 0);
            } else {
                rowOnes[i][j] = rowOnes[i][j - 1] + ((mat[i][j] == 1) ? 1 : 0);
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                colOnes[i][j] = ((mat[i][j] == 1) ? 1 : 0);
            } else {
                colOnes[i][j] = colOnes[i - 1][j] + ((mat[i][j] == 1) ? 1 : 0);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //figure out combinations of rectangles ending at this node
            if (mat[i][j] == 0) {
                //no rectangle possible if this submatrix is pivoted at a 0
                continue;
            }
            numAllSquaresOne += 1;
            int maxBreadth = j;
            int maxHeight = i;
            //check from 1 to maxBreadth

            for (int w = 0; w < maxBreadth; w++) {
                //see if you can make 1 x w, sliding it each time
                int onesFromWidthWToJ = rowOnes[i][j] - (w == 0 ? 0 : rowOnes[i][w - 1]);
                if (onesFromWidthWToJ == j - (w - 1)) {
                    numAllSquaresOne += 1;
                }
            }
            for (int h = 0; h < maxHeight; h++) {
                //see if you can make h x 1, sliding it down each time
                int onesFromHeightHToI = rowOnes[i][j] - (h == 0 ? 0 : rowOnes[h - 1][j]);
                if (onesFromHeightHToI == i - (h - 1)) {
                    numAllSquaresOne += 1;
                }
            }
            for (int sq = 2; sq < min(maxBreadth, maxHeight); sq++) {
                //see if sq * sq is possible
                int topRight = sq;
                //if topRight
                if ((rowOnes[i][j - sq] == sq) && colOnes[i][sq] == 1) {
                    numAllSquaresOne += 1;
                }
            }

            //check from 1 to maxHeight

            //check from 2 to min(maxBreadth, maxHeight)

            //for each combination check if it is valid

            //if yes, increment the sum
        }
    }

    std::cout << rowOnes;
    std::cout << colOnes;
    return numAllSquaresOne;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<vector<int>> m = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}};

    std::cout << numSubmat(m);
    return 0;
}
