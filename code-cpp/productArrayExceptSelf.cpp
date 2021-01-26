#include <bits/stdc++.h>

/*
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * So, basically, lets take 4 numbers: a, b, c, d
 * Expected: bcd, acd, adb, bcd
 * First thought: Take two arrays & in one do prefix mult from left & right
 * Then divide them.
 *
 * L: a ab abc abcd
 * R: abcd bcd cd d
 * D: bcd, a/cd, ab/d, abc
 * This obviousy doesn't work. Then I saw a pattern. Shifting by 1 would work
 * as I need to ignore the abcd part. Also I'd need to multiply
 *
 * L: 1 a ab abc
 * R: bcd cd d 1
 * M: bcd acd abc abc
 */

ostream& operator<<(ostream& c, vector<int>& vs) {
    for (auto v : vs) {
        c << " -> " << v;
    }
    c << std::endl;
    return c;
}

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 0);
    int temp = 1;
    int n = nums.size();

    // left pass
    for (int i = 0; i < n; i++) {
        temp = i == 0 ? 1 : nums[i - 1];
        res[i] = i == 0 ? 1 : res[i - 1] * temp;
    }

    // right pass
    for (int i = n - 1; i >= 0; i--) {
        temp = i == (n - 1) ? 1 : temp * nums[i + 1];  // 4
        res[i] = i == (n - 1) ? res[i] : res[i] * temp;
        // std::cout << "temp: " << temp << " res [" << i << "] : " << res[i]
        //           << endl;
    }
    // std::cout << res;

    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // vector<int> nums = {1, 2, 3, 4};
    vector<int> nums = {3, 11, -4};
    vector<int> res = productExceptSelf(nums);
    std::cout << res;
    return 0;
}
