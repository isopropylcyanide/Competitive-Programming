#include <bits/stdc++.h>
#define MAX 25

int dp[MAX];
int numTrees(int n) {
    //basically any node from 1 to n can become the root
    //whiever becomes the root, the ways(left) * ways(right) is the number of ways
    if (n <= 1) {
        return 1;
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += numTrees(i - 1) * numTrees(n - i);
    }
    return count;
}

int numTreesMemoized(int n) {
    //basically any node from 1 to n can become the root
    //whiever becomes the root, the ways(left) + ways(right) is the number of ways
    if (n <= 1) {
        return 1;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += numTrees(i - 1) * numTrees(n - i);
    }
    dp[n] = count;
    return count;
}

int numTreesBottomUp(int n) {
    //basically any node from 1 to n can become the root
    //whiever becomes the root, the ways(left) + ways(right) is the number of ways
    if (n <= 1) {
        return 1;
    }
    memset(dp, 0, MAX);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = dp[i] + (dp[i - j] * dp[j - 1]);
        }
    }

    return dp[n];
}

int numTreesCatalan(int n) {
    long long ans = 1, i;
    for (i = 1; i <= n; i++)
        ans = ans * (i + n) / i;
    return ans / i;
}

int main() {
    std::cout << numTreesCatalan(3) << std::endl;
    std::cout << numTreesCatalan(5) << std::endl;
    std::cout << numTreesCatalan(7) << std::endl;
}
