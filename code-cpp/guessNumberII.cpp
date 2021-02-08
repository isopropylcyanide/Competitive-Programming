#include <bits/stdc++.h>

/**
* I pick a number from 1 to n. You have to guess which number I picked.
*/
int dp[205][205];
int f(int l, int r) {
    if (l >= r) {
        //no cost
        dp[l][r] = 0;
        return 0;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    //cost(1,n)=i+max(cost(1,i−1),cost(i+1,n))
    int ans = INT_MAX;
    int mid = (l + r) / 2;
    for (int i = mid; i <= r; i++) {
        int _ans = i + max(f(l, i - 1), f(i + 1, r));
        ans = min(ans, _ans);
    }
    dp[l][r] = ans;
    return ans;
}
int getMoneyAmount(int n) {
    for (int i = 0; i < 205; i++) {
        for (int j = 0; j < 205; j++) {
            dp[i][j] = -1;
        }
    }
    return f(1, n);
}

int main() {
    std::cout << getMoneyAmount(200) << endl;
    return 0;
}
