#include <bits/stdc++.h>

/**
 * Given an unsorted integer array nums, find the smallest missing positive integer
*/

int firstMissingPositiveNormal(vector<int>& nums) {
    set<long long> elems;
    long long maxVal = INT_MIN;
    for (auto num : nums) {
        elems.insert(num);
        maxVal = max(maxVal, (long long)num);
    }
    if (maxVal <= 0) {
        return 1;
    }
    for (long long i = 1; i <= maxVal + 1; i++) {
        if (elems.find(i) == elems.end()) {
            return i;
        }
    }
    return nums.size() + 1;
}

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    bool oneExists = false;
    //discard zeroes, negatives and out of bound indices
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            oneExists = true;
        }
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = 1;
        }
    }
    if (!oneExists) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        int val = abs(nums[i]);
        if (val == n) {
            //special case
            nums[0] = abs(nums[0]) * -1;
        } else {
            nums[val] = abs(nums[val]) * -1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (nums[i] > 0) {
            return i;
        }
    }
    if (nums[0] > 0) {
        //nobody invalidated this
        return n;
    }
    return n + 1;
}

int main() {
    // vector<int> nums = {3, 4, -1, 1};
    vector<int> nums = {1, 5, 3, 3, -2};
    // vector<int> nums = {-5};
    // vector<int> nums = {7, 8, 9, 11, 12};
    // vector<int> nums = {0, 1, 2};
    std::cout << firstMissingPositive(nums) << endl;
    return 0;
}