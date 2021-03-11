#include <bits/stdc++.h>

int trap(vector<int>& height) {
    stack<int> boundBars;
    int n = height.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        while (!boundBars.empty() && height[i] > height[boundBars.top()]) {
            int prevBarIdx = boundBars.top();
            boundBars.pop();
            if (boundBars.empty()) {
                break;
            }
            int minHeight = min(height[i], height[boundBars.top()]) - height[prevBarIdx];
            //find new prev bound bar and then calculate width
            int maxWidth = i - boundBars.top() - 1;
            ans += minHeight * maxWidth;
        }
        boundBars.push(i);
    }
    return ans;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << trap(height) << endl;
    return 0;
}