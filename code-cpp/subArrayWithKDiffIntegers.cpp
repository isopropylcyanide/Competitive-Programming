#include <iostream>
#include <vector>
#include <map>

// Given an array nums of positive integers, find number of (contiguous, not necessarily distinct)
// subarray of where the number of different integers in that subarray is exactly k.

int subarraysWithAtmostKDistinct(std::vector<int> &nums, int k) {
    std::map<int, int> numCount;
    int l = 0, ans = 0;
    for (int r = 0; r < nums.size(); r++) {
        if (numCount[nums[r]] == 0) {
            k = k - 1;
        }
        numCount[nums[r]] += 1;
        while (k < 0) {
            numCount[nums[l]] = numCount[nums[l]] - 1;
            if (numCount[nums[l]] == 0) {
                k += 1;
            }
            l += 1;
        }
        ans = ans + (r - (l - 1));
    }
    return ans;
}

int subarraysWithKDistinct(std::vector<int> &nums, int k) {
    int i = subarraysWithAtmostKDistinct(nums, k);
    int j = subarraysWithAtmostKDistinct(nums, k - 1);
    std::cout << "Atmost " << k << " : " << i << std::endl;
    std::cout << "Atmost " << k - 1 << " : " << j << std::endl;
    return i - j;
}

int main() {
    std::vector<int> v = {1, 2, 1, 2, 3};
    std::cout << subarraysWithKDistinct(v, 2) << std::endl;
    return 0;
}
