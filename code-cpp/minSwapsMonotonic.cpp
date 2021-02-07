#include <bits/stdc++.h>

/**
* Given A and B, return the minimum number of swaps to make both sequences strictly
* increasing. It is guaranteed that the given input always makes it possible.
*/

template <typename T>
ostream& operator<<(ostream& c, vector<T>& vs) {
    for (auto v : vs) {
        c << " -> " << v;
    }
    c << std::endl;
    return c;
}

int minSwap(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> swap(n, 0);
    vector<int> notSwap(n, 0);
    swap[0] = 1;

    for (int i = 1; i < n; i++) {
        //set to swap the entire array
        notSwap[i] = n;
        swap[i] = n;
        if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
            //more support to swap here
            //3 4
            //5 6
            swap[i] = swap[i - 1] + 1;
            notSwap[i] = notSwap[i - 1];
        }
        if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
            //3 7
            //6 9
            // ->      or
            //6 7      3 9
            //3 9      6 7
            //or swap at i
            swap[i] = min(swap[i], notSwap[i - 1] + 1);
            //not swapping at i
            notSwap[i] = min(notSwap[i], swap[i - 1]);
        }
    }
    return min(swap[n - 1], notSwap[n - 1]);
}

int main() {
    std::vector<int> A = {0, 4, 4, 5, 9};
    std::vector<int> B = {0, 1, 6, 8, 10};
    std::cout << minSwap(A, B) << endl;
    return 0;
}
