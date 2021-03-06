#include <bits/stdc++.h>

int inBounds(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

//to avoid redundant dfs from every node,
//store the max best path that is achievable at a node..
//next time we land on a node, if previously path had a better length
//we do not solve it

int dp[201][201] = {0};

int dfs(int i, int j, int n, int m, vector<vector<int>>& matrix) {
    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    for (int dir = 0; dir < 4; dir++) {
        int newX = i + dir_x[dir];
        int newY = j + dir_y[dir];
        if (inBounds(newX, newY, n, m) && matrix[newX][newY] > matrix[i][j]) {
            dp[i][j] = max(dp[i][j], dfs(newX, newY, n, m, matrix));
        }
    }
    dp[i][j] = dp[i][j] + 1;
    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int ans = 1;
    //from each cell, start a bfs if possible in an incr manner
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << "DFS from " << i << ", " << j << ": ";
            int thisAns = dfs(i, j, n, m, matrix);
            ans = max(ans, thisAns);
            std::cout << thisAns << endl;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}};
    std::cout << longestIncreasingPath(matrix) << std::endl;
    return 0;
}