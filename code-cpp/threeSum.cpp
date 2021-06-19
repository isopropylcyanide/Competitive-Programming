#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 */
vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<tuple<int, int, int>> visited;

    for (int i = 0; i < n; i++) {
        int sumRequired = -nums[i];
        int l = i + 1, r = n - 1;
        while (l < r) {
            //see what all pairs match (l is small, r is large)
            int current = nums[l] + nums[r];
            if (current == sumRequired) {
                //output the tuple, i, l, r and we advance both because no duplicates
                if (visited.find(make_tuple(nums[i], nums[l], nums[r])) == visited.end()) {
                    visited.insert(make_tuple(nums[i], nums[l], nums[r]));
                    ans.push_back({nums[i], nums[l], nums[r]});
                }
                l += 1;
                r -= 1;
            } else if (current > sumRequired) {
                r -= 1;
            } else if (current < sumRequired) {
                l += 1;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> sums = {-1, 0, 1, 2, -1, -4};

    for (auto v :  threeSum(sums)) {
        for (auto k : v) {
            cout << k << " -> ";
        }
        cout << endl;
    }
    return 0;
}