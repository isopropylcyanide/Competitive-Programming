#include <bits/stdc++.h>

int trapNoSpace(vector<int>& height) {
    int n = height.size();
    vector<int> left(n), right(n);
    int ans = 0;

    int lMax = height[0], rMax = height[n - 1];
    int l = 0, r = n - 1;

    while (l <= r) {
        int envelopeMin = min(lMax, rMax);
        lMax = max(lMax, height[l]);
        rMax = max(rMax, height[r]);
        if (lMax <= rMax) {
            ans += lMax - height[l];
            l += 1;
        } else {
            ans += rMax - height[r];
            r -= 1;
        }
    }
    return ans;
}

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> left(n), right(n);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        left[i] = i == 0 ? height[i] : max(left[i - 1], height[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        right[i] = i == n - 1 ? height[n - 1] : max(right[i + 1], height[i]);
    }
    for (int i = 0; i < n; i++) {
        ans += min(left[i], right[i]) - height[i];
    }
    return ans;
}

int trap_(vector<int>& height) {
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
    std::cout << trapNoSpace(height) << endl;
    return 0;
}