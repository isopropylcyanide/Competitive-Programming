#include<bits/stdc++.h>

using namespace std;

/**
 * Given a mysterious function He has an integer array arr and an integer target and he wants
 * to find the values l and r that make the value |func(arr, l, r) - target| minimum possible.
 *
 * Return the minimum possible value of |func(arr, l, r) - target|.
 * Notice that func should be called with the values l and r where 0 <= l, r < arr.length.
 *
 * func(arr, l, r){
 *     if (r < l){
 *         return -100000000;
 *     }
 *     ans = arr[l]
 *     for (i = l + 1, i <= r; i++) {
 *         ans = ans & arr[i]
 *     }
 *     return ans
 * }
 * @return
 */

ostream &operator<<(ostream &c, set<int> &s) {
    for (auto val : s) {
        c << val << " -> ";
    }
    return c;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

// idea is that for each index, there exists only a subset of unique values after AND
int closestToTarget(vector<int> &arr, int target) {
    int ans = INT_MAX;
    set<int> globalAnd;

    // loop through each index, this becomes our right hand pivot 'r'
    for (int i = 0; i < arr.size(); i++) {
        // include the AND of values for all
        set<int> localAnd = {arr[i]};
//        std::cout << "\n Starting for i: " << i << endl;
//        std::cout << "Global set start: " << globalAnd << endl;
//        std::cout << "Local set start:" << localAnd << endl;

        // for all items in global set, try to find the new AND values for this index
        for (auto val: globalAnd) {
            localAnd.insert(arr[i] & val);
//            std::cout << "Inserting:" << (arr[i] & val) << endl;
        }
        // try to find the global minimum for each value in the set
        for (auto val: localAnd) {
            ans = min(ans, abs(val - target));
//            std::cout << "Minimum value: " << ans << endl;
        }
        // the global set now becomes the new local set
        globalAnd = localAnd;
//        std::cout << "Local set end: " << globalAnd << endl;
//        std::cout << "Global set end: " << localAnd << endl;
    }
    return ans;
}

int main() {
    vector<int> v = {9, 12, 3, 7, 15};
    std::cout << closestToTarget(v, 5) << endl;

    v = {1, 2, 4, 8, 16};
    std::cout << closestToTarget(v, 0) << endl;;
    return 0;
}