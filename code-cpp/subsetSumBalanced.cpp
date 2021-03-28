#include <bits/stdc++.h>

bool canPartition(vector<int>& nums) {
    int totalSum = 0;
    // find sum of all array elements
    for (int num : nums) {
        totalSum += num;
    }
    // if totalSum is odd, it cannot be partitioned into equal sum subset
    if (totalSum % 2 != 0) {
        return false;
    }
    int subSetSum = totalSum / 2;
    int n = nums.size();
    vector<bool> dp(subSetSum + 1, false);
    dp[0] = true;
    for (int curr : nums) {
        for (int j = subSetSum; j >= curr; j--) {
            dp[j] = dp[j] || dp[j - curr];
        }
    }
    return dp[subSetSum];
}

int main() {
    // vector<int> s = {1, 5, 11, 5};
    // vector<int> s = {1, 2, 3, 5};
    // vector<int> s = {1};
    // vector<int> s = {1, 2, 3};
    // vector<int> s = {1, 3, 4, 4};
    vector<int> s = {2, 2, 1, 1};
    std::cout << canPartition(s) << endl;
    return 0;
}