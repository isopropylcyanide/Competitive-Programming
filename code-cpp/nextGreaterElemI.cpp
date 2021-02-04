#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream &operator<<(ostream &c, vector<T> &vec) {
    for (auto t : vec) {
        c << t << ' ';
    }
    return c;
}

vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> nextGreater(n, -1);
    // for (int i = 0; i < n; i++) {
    //     nums.push_back(nums[i]);
    // }
    stack<int> stack;

    for (int i = 0; i < n; i++) {
        while (!stack.empty() && nums[i] > nums[stack.top()]) {
            int top = stack.top();
            std::cout << "Next greater for index " << top << " [" << nums[top] << "]: " << i << " [" << nums[i] << "]\n";
            nextGreater[top] = nums[i];
            stack.pop();
        }
        if (i < n) {
            //don't repeat forever
            stack.push(i);
        }
    }
    //for everything that is
    return nextGreater;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    //put elems in a map
    map<int, int> elemMap;
    for (int i = 0; i < nums2.size(); i++) {
        elemMap[nums2[i]] = i;
    }
    //get all
    vector<int> nextElements = nextGreaterElements(nums2);
    std::cout << "Yay: " << nextElements << endl;
    vector<int> output;
    for (int i = 0; i < nums1.size(); i++) {
        int idx = elemMap[nums1[i]];
        output.push_back(nextElements[idx]);
    }
    return output;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // vector<int> nums1 = {4, 1, 2};
    // vector<int> nums2 = {1, 3, 4, 2};
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    std::cout << ans << endl;
    return 0;
}
