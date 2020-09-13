#include<bits/stdc++.h>

ostream &operator << (ostream &c, vector<vector<int>> &dp){
    for (int i = 0; i < dp.size(); i++){
            for (int j = 0; j < dp[0].size(); j++){
                c << dp[i][j] << " -> ";
            }
            c << endl;
        }
    return c;
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0){
            return 0;
        }
        int m = obstacleGrid[0].size();
        if (m == 0){
            return 0;
        }
        if (n == 1 && m == 1){
            return obstacleGrid[0][0] == 0 ? 1 : 0;
        }
        vector<vector<int>> dp(2, vector<int>(m + 1));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << " i : " << i << " j : " << j << endl;
                if (i == 1 && j == 1 && obstacleGrid[0][0] == 0){
                    dp[1][1] = 1;
                }
                else if (obstacleGrid[i - 1][j - 1] == 0){
                    dp[1][j] = dp[0][j] + dp[1][j - 1];
                }
            }
            std::cout << "\nPrinting array\n";
            std::cout << dp;
            //swap array
            std::cout << "\nSwapping array\n";
            for (int j = 0; j <= m; j++){
                dp[0][j] = dp[1][j];
                dp[1][j] = 0;
            }
            std::cout << dp;
        }
        return dp[0][m];
    }
};

class SolutionWithNonOptimalSpace {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0){
            return 0;
        }
        int m = obstacleGrid[0].size();
        if (m == 0){
            return 0;
        }
        if (n == 1 && m == 1){
            return obstacleGrid[0][0] == 0 ? 1 : 0;
        }
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (i == 1 && j == 1 && obstacleGrid[0][0] == 0){
                    dp[1][1] = 1;
                }
                else if (obstacleGrid[i - 1][j - 1] == 0){
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                std::cout << "\nPrinting array\n";
                std::cout << dp;
            }
        }
        return dp[n][m];
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec {
        {0, 0, 1},
        {0, 0, 0},
        {0, 0, 0}
    };
    vector<vector<int>> vec2 {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    vector<vector<int>> vec3 {
        {1, 0}
    };
    std::cout << std:: endl << s.uniquePathsWithObstacles(vec) << std::endl;

}