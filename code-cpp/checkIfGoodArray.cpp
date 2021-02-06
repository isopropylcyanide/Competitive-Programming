#include <bits/stdc++.h>

/*
 * Given an array nums of positive integers. Your task is to select some subset of nums, 
 * multiply each element by an integer and add all these numbers. The array is said to be
 *  good if you can obtain a sum of 1 from the array by any possible subset and multiplicand.
 */
ostream& operator<<(ostream& c, vector<int>& vs) {
    for (auto v : vs) {
        c << " -> " << v;
    }
    c << std::endl;
    return c;
}

int __gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return __gcd(b, a % b);
}

bool isGoodArray(vector<int>& nums) {
    int gcdCombined = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        gcdCombined = __gcd(gcdCombined, nums[i]);
    }
    return gcdCombined == 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> nums_a = {12, 5, 7, 23};
    vector<int> nums_b = {29, 6, 10};
    vector<int> nums_c = {3, 6};
    std::cout << isGoodArray(nums_a) << std::endl;
    std::cout << isGoodArray(nums_b) << std::endl;
    std::cout << isGoodArray(nums_c) << std::endl;
    return 0;
}
