#include <bits/stdc++.h>

/**
* Given an array of distinct integers arr, where arr is sorted in ascending order,
* return the smallest index i that satisfies arr[i] == i. If there is no such index, return -1.
*/

int binarySearch(vector<int> points) {
    int n = points.size();
    int l = 0, r = n - 1;
    int best = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int midValue = points[mid];

        if (midValue >= mid) {
            //jackpot but need to check for more
            if (midValue == mid) {
                best = mid;
            }
            r = mid - 1;
        }
        if (midValue < mid) {
            //0 & 2
            //potential for answer in right side as i will increase by 1 and midValue by more
            l = mid + 1;
        }
    }
    return best == -1 ? -1 : best;
}

int fixedPoint(vector<int>& arr) {
    return binarySearch(arr);
}

int main() {
    // vector<int> points = {-10, -5, 0, 3, 7};
    // vector<int> points = {0, 2, 5, 8, 17};
    // vector<int> points = {-10, -5, 3, 4, 7, 9};
    // vector<int> points = {};
    // vector<int> points = {0};
    // vector<int> points = {1};
    vector<int> points = {-10, -5, -2, 0, 4, 5, 6, 7, 8, 9, 10};
    // vector<int> points = {-10, -5, 3, 4, 7, 9};
    std::cout << fixedPoint(points) << endl;
    return 0;
}
