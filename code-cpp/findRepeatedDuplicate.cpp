#include <bits/stdc++.h>

/**
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] 
 * inclusive. There is only one repeated number in nums, return this repeated number.
*/

int findDuplicate(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int num = abs(nums[i]);
        if (nums[num] < 0) {
            //booooooom
            return num;
        } else {
            nums[num] = -nums[num];
        }
    }
    return -1;
}

int main() {
    // vector<int> grid = {3, 1, 3, 4, 2};
    // vector<int> grid = {1, 3, 4, 2, 2};
    vector<int> grid = {1, 2};
    std::cout << findDuplicate(grid) << endl;
    return 0;
}