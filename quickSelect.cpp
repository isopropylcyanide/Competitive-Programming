#include <bits/stdc++.h>
using namespace std;

// Quickly return the kth largest/smallest in array

int partition(vector<int> &A, int l, int h){
    // Return the pivot when the array is partitioned from l to h
    // Set pivot as the highest value
    int pivotIndex = l, pivot = A[h];
    for (int i = l; i < h; i++){
        if (A[i] < pivot)
            swap(A[i], A[pivotIndex++]);
    }
    swap(A[h], A[pivotIndex]);
    return pivotIndex;
}


int quickSmallest(vector<int> &A, int l, int h, int k){
    if (k < 0 || k > h - l + 1)
        return -1;
    int pivot = partition(A, l, h);
    int numLess = pivot - l + 1;
    if (numLess == k)
        return A[pivot];
    else if (numLess > k)
        return quickSmallest(A, l, pivot -1, k);
    else
        return quickSmallest(A, pivot + 1, h, k - numLess);
}


int main(){
    // Sorted order is 1, 2, 9, 12, 23, 30, 50
    vector<int> A = {1, 23, 12, 9, 30, 2, 50, -3, 60};
    cout << quickSmallest(A, 0, A.size() -1, 1) << endl;
    cout << quickSmallest(A, 0, A.size() -1, 2) << endl;
    cout << quickSmallest(A, 0, A.size() -1, 3) << endl;
    cout << quickSmallest(A, 0, A.size() -1, 4) << endl;
    cout << quickSmallest(A, 0, A.size() -1, 5) << endl;
    cout << quickSmallest(A, 0, A.size() -1, 6) << endl;
    cout << quickSmallest(A, 0, A.size() -1, 7) << endl;

}
