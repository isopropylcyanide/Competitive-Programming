#include <bits/stdc++.h>
using namespace std;

// Use mergeSortRec to sort numbers in ascending order
int N;
vector<int> A;

inline void display(vector<int> &X){
    cout << endl;
    for (auto a : X)
        cout << a << " -> ";
    cout << endl;
}

void merge(int l, int m, int h){
    // We have two subArrays [l:m] and [m + 1:h]
    // merge them accordingly
    vector<int> C(N, 0);
    int i = l, j  = m +1, k = l;
    while (i <= m && j <= h){
        if (A[i] < A[j])
            C[k++] = A[i++];
        else
            C[k++] = A[j++];
    }
    while (i <= m)
        C[k++] = A[i++];
    while (j <= h)
        C[k++] = A[j++];
    for (int i = l; i < k; i++)
        A[i] = C[i];
}

void mergeSortRec(int l, int h){
    if(l < h){
        int m = l + (h - l)/2;
        mergeSortRec(l, m);
        mergeSortRec(m + 1, h);
        merge(l, m, h);
    }
}

void mergeSortIter(int h){
    int block, l;
    for (block = 1; block <= h; block = 2 * block){
        for (l = 0; l < h; l += 2 * block){
            int m = l + block - 1;
            int r = min(l + 2 * block -1, h);
            merge(l, m, r);
        }
    }
}


int main(){
    A = {20, 12, 9, 8, 7 , 4, 3, 1};
    N = A.size();
    display(A);
    mergeSortIter(N -1);
    display(A);
    return 0;
}
