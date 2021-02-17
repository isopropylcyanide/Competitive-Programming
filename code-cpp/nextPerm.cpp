#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int> &);
};

ostream &operator<<(ostream &c, vector<int> A) {
    for (auto a : A)
        c << a << " ";
    c << endl;
    return c;
}

void Solution::nextPermutation(vector<int> &A) {
    // if array is sorted in reverse order
    // there's no nextPerm
    bool revSorted = true;
    int index = -1;

    for (int i = 0; i < A.size() - 1; i++)
        if (A[i] < A[i + 1]) {
            revSorted = false;
            index = i;
            // break;
        }

    if (revSorted) {
        reverse(A.begin(), A.end());
        return;
    }
    // else there's index j > i such that A[j] > A[i]
    int highestJ = 0, i = index;
    for (int j = i + 1; j < A.size(); j++) {
        if (A[j] > A[i])
            highestJ = j;
    }
    // swap the highest
    swap(A[i], A[highestJ]);

    // Reverse A from i +1 till end
    reverse(A.begin() + i + 1, A.end());
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solution s;
    s.nextPermutation(A);
    cout << "\nGetting nextPerm: ";
    for (auto a : A)
        cout << a << " ";

    cout << endl;
    return 0;
}
