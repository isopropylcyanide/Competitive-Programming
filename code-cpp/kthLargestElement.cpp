#include <bits/stdc++.h>

template <typename T>
ostream &operator<<(ostream &c, vector<T> &vs) {
    for (auto v : vs) {
        c << v << " -> ";
    }
    c << std::endl;
    return c;
}

int partition(vector<int> &A, int l, int r) {
    //find pivot when viewed from nums[l:r] inclusive
    int pivot = A[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (A[j] <= pivot) {
            //problem
            swap(A[j], A[i]);
            i += 1;
        }
    }
    swap(A[i], A[r]);
    return i;
}

int findKthLargestUtil(int l, int r, vector<int> &nums, int k) {
    //find any random element as a pivot
    int n = r - l + 1;
    int kInRank = n - k;
    while (true) {
        int rank = partition(nums, l, r);
        if (rank < kInRank)  // found a number too low, start index after it
            l = rank + 1;
        else if (rank > kInRank)  // found a number too high, end index before it
            r = rank - 1;
        else
            return nums[rank];
    }
    return -1;
}

int findKthLargest(vector<int> &nums, int k) {
    return findKthLargestUtil(0, nums.size() - 1, nums, k);
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    std::cout << findKthLargest(nums, 1) << endl;
    std::cout << findKthLargest(nums, 2) << endl;
    std::cout << findKthLargest(nums, 3) << endl;
    std::cout << findKthLargest(nums, 4) << endl;
    std::cout << findKthLargest(nums, 5) << endl;
    std::cout << findKthLargest(nums, 6) << endl;
    return 0;
}
