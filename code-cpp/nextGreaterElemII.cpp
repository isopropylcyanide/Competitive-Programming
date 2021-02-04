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
    for (int i = 0; i < n; i++) {
        nums.push_back(nums[i]);
    }
    stack<int> stack;

    for (int i = 0; i < n * 2; i++) {
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> heights = {4, 3, 1, 2, 5};
    // vector<int> heights = {2, 1, 2};
    // vector<int> heights = {1, 2, 1};
    vector<int> ans = nextGreaterElements(heights);
    std::cout << ans << endl;
    return 0;
}
