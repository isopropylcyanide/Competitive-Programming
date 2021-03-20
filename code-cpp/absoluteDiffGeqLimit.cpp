#include <bits/stdc++.h>

// Perform a range minimum query given an input vector
vector<int> stMin, stMax;

/********************************RANGE MIN SEGMENT TREE***************************/
void constructSegMinUtil(vector<int> &inp, int pos, int low, int high, vector<int> &st) {
    // Utility method for the seg tree construction for range min query
    assert(low <= high);
    if (low == high) {  //reached a leaf node
        st[pos] = inp[low];
        return;
    } else {  //descend into the left tree and fill the values
        int mid = (low + high) / 2;
        constructSegMinUtil(inp, 2 * pos + 1, low, mid, st);       //left child
        constructSegMinUtil(inp, 2 * pos + 2, mid + 1, high, st);  //right child
        st[pos] = min(st[2 * pos + 1], st[2 * pos + 2]);
    }
}
void constructSegMinTree(vector<int> &A) {
    // COnstructs a seg tree given a vector A
    int sizeSegTree = pow(2, int(ceil(log2(A.size())))) * 2 - 1;
    stMin.resize(sizeSegTree, INT_MAX);
    constructSegMinUtil(A, 0, 0, A.size() - 1, stMin);
}

int rMinQUtil(int qL, int qH, int l, int h, int pos) {
    // Utility function that, given a range calculates the minimum in that range
    if (qL > h || qH < l)  //no overlap
        return INT_MAX;
    if (qL <= l && qH >= h)  //total overlap
        return stMin[pos];
    //else partial overlap
    int mid = (l + h) / 2;
    return min(rMinQUtil(qL, qH, l, mid, 2 * pos + 1),
               rMinQUtil(qL, qH, mid + 1, h, 2 * pos + 2));
}
/********************************RANGE MIN SEGMENT TREE***************************/

/********************************RANGE MAX SEGMENT TREE***************************/
void constructSegMaxUtil(vector<int> &inp, int pos, int low, int high, vector<int> &st) {
    // Utility method for the seg tree construction for range Max query
    assert(low <= high);
    if (low == high) {  //reached a leaf node
        st[pos] = inp[low];
        return;
    } else {  //descend into the left tree and fill the values
        int mid = (low + high) / 2;
        constructSegMaxUtil(inp, 2 * pos + 1, low, mid, st);       //left child
        constructSegMaxUtil(inp, 2 * pos + 2, mid + 1, high, st);  //right child
        st[pos] = max(st[2 * pos + 1], st[2 * pos + 2]);
    }
}

void constructSegMaxTree(vector<int> &A) {
    // COnstructs a seg tree given a vector A
    int sizeSegTree = pow(2, int(ceil(log2(A.size())))) * 2 - 1;
    stMax.resize(sizeSegTree, INT_MIN);
    constructSegMaxUtil(A, 0, 0, A.size() - 1, stMax);
}

int rMaxQUtil(int qL, int qH, int l, int h, int pos) {
    // Utility function that, given a range calculates the minimum in that range
    if (qL > h || qH < l)  //no overlap
        return INT_MIN;
    if (qL <= l && qH >= h)  //total overlap
        return stMax[pos];
    //else partial overlap
    int mid = (l + h) / 2;
    return max(rMaxQUtil(qL, qH, l, mid, 2 * pos + 1),
               rMaxQUtil(qL, qH, mid + 1, h, 2 * pos + 2));
}
/********************************RANGE MAX SEGMENT TREE***************************/

int longestSubarray(vector<int> &nums, int limit) {
    int n = nums.size();
    constructSegMinTree(nums);
    constructSegMaxTree(nums);

    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         // std::cout << "\nMin [" << i << "," << j << "]: " << rMinQUtil(i, j, 0, n - 1, 0);
    //         // std::cout << "\nMax [" << i << "," << j << "]: " << rMaxQUtil(i, j, 0, n - 1, 0);
    //     }
    // }
    // return 0;

    int l = 0, r = 1;
    int ans = 1;
    while (l <= r && r <= n - 1) {
        //see if you can extend this range,
        //largest element in range = abs(min[l,r] max(l, r),
        //find largest element in range (l, r):: how?
        //is it maxLR[r] ? no, it's max(l, r)
        //also find smallest element in this range...take the diff
        int maxVal = rMaxQUtil(l, r, 0, n - 1, 0);
        int minVal = rMinQUtil(l, r, 0, n - 1, 0);
        int diff = abs(maxVal - minVal);
        if (diff <= limit) {
            std::cout << "\nValid range [" << l << "," << r << "]: " << diff;
            ans = max(ans, r - l + 1);
            r = r + 1;
        } else {
            l = l + 1;
        }
    }

    return ans;
}

int main() {
    // vector<int> A{8, 2, 4, 7};
    // vector<int> A{0, 1, 2, 4, 7, 2};
    vector<int> A{4, 2, 2, 2, 4, 4, 2, 2};
    // int ans = longestSubarray(A, 4);
    // int ans = longestSubarray(A, 5);
    int ans = longestSubarray(A, 0);
    std::cout << "\nAnswer:" << ans << endl;
    return 0;
}