#include <bits/stdc++.h>

/*
 * Given an integer n, return the least number of perfect square numbers that sum to n.
 */

int f(int n, vector<int> &dp) {
    //for every num from 1 to sqrt n, try it
    if (n <= 1) {
        dp[n] = n;
        return n;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int minSquaresUsed = n;
    for (int i = 1; i * i <= n; i++) {
        int squaresUsed = n / (i * i);
        int ans = squaresUsed + f(n - (squaresUsed * (i * i)), dp);
        minSquaresUsed = min(minSquaresUsed, ans);
    }
    dp[n] = minSquaresUsed;
    return minSquaresUsed;
}

int numSquares(int n) {
    vector<int> dp(n + 1, -1);
    return f(n, dp);
}

int numSquares_Rec(int n) {
    //for every num from 1 to sqrt n, try it
    // std::cout << "rec(" << n << ")\n";
    if (n <= 1) {
        return n;
    }
    int minSquaresUsed = n;
    for (int i = 1; i * i <= n; i++) {
        int squaresUsed = n / (i * i);
        int ans = squaresUsed + numSquares_Rec(n - (squaresUsed * (i * i)));
        minSquaresUsed = min(minSquaresUsed, ans);
    }
    return minSquaresUsed;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // std::cout << numSquares_Rec(12) << std::endl;
    // std::cout << numSquares_Rec(13) << std::endl;
    // std::cout << numSquares_Rec(41) << std::endl;
    // std::cout << numSquares_Rec(42) << std::endl;
    // std::cout << numSquares_Rec(43) << std::endl;
    std::cout << numSquares(31000) << std::endl;
    std::cout << numSquares_Rec(31000) << std::endl;
    return 0;
}
