#include <bits/stdc++.h>
using namespace std;

int findPivot(int l, int r, vector<int>& A) {
    if (A[l] < A[r]) {
        return 0;
    }
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (A[mid] > A[mid + 1]) {
            //this is the inflection
            return mid + 1;
        } else {
            if (A[mid] < A[l]) {
                //this is a problem..its in the left array
                r = mid - 1;
            } else {
                //okay, could be in right
                l = mid + 1;
            }
        }
    }
    return 0;
}

int binarySearch(int l, int r, vector<int>& A, int target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (A[mid] == target) {
            //this is the inflection
            return mid;
        } else {
            if (A[mid] > target) {
                r = mid - 1;
            } else {
                //okay, could be in right
                l = mid + 1;
            }
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    // distinct values
    int l = 0, r = nums.size() - 1;
    if (r == 0) {
        return nums[0] == target;
    }
    //find the rotation index first
    int pivot = findPivot(l, r, nums);

    if (nums[pivot] == target) {
        //jackpot
        return pivot;
    }
    if (pivot == 0) {
        return binarySearch(l, r, nums, target);
    }
    //search in either left or right arrays
    if (target < nums[0]) {
        //its in the left senment
        return binarySearch(pivot + 1, r, nums, target);
    } else {
        return binarySearch(l, pivot - 1, nums, target);
    }
}

int main() {
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums = {1};
    // std::cout << search(nums, 0) << endl;
    std::cout << search(nums, 0) << endl;
}