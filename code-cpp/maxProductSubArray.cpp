#include <bits/stdc++.h>

/*
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 */

template <typename T>
ostream& operator<<(ostream& c, vector<T>& vs) {
    for (auto v : vs) {
        c << " -> " << v;
    }
    c << std::endl;
    return c;
}

int maxProduct(vector<int>& nums) {
    if (nums.size() < 1) {
        return 0;
    }
    int _max = nums[0];
    int maxSoFar = nums[0];
    int minSoFar = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int tempMax = maxSoFar;
        maxSoFar = max(nums[i], max(nums[i] * maxSoFar, nums[i] * minSoFar));
        minSoFar = min(nums[i], min(nums[i] * tempMax, nums[i] * minSoFar));

        _max = max(_max, max(maxSoFar, minSoFar));
    }
    return _max;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> nums_a = {2, 3, -2, 4};
    vector<int> nums_b = {2, 3, -2, -4};
    vector<int> nums_c = {-2, 0, -1, 50};
    // std::cout << maxProduct(nums_a) << std::endl;
    // std::cout << maxProduct(nums_b) << std::endl;
    std::cout << maxProduct(nums_c) << std::endl;
    return 0;
}
