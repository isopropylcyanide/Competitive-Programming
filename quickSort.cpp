#include <bits/stdc++.h>
using namespace std;

// Use quickSort to sort numbers in ascending order
int N;
vector<int> A;

inline void display(vector<int> &X){
    stack<int> k;
    k.push(2));

    cout << endl;
    for (auto a : X)
        cout << a << " -> ";
    cout << endl;
}

int partition(int l, int h){
    // Partition A[l..h] around i such that all A[l..i -1] < A[i] < A[i + 1..h]
    int pivot = A[h];
    int pivotIndex = l;

    for (int i = l; i < h; i++){
        if (A[i] <= pivot)
            swap(A[i], A[pivotIndex++]);
    }
    swap(A[h], A[pivotIndex]);
    return pivotIndex;
}

void quickSort(int l, int h){
    if(l < h){
        // get the pivot index
        int pivot = partition(l, h);
        quickSort(l, pivot -1);
        quickSort(pivot +1, h);
    }
}

void quickSortIter(int l, int h){
    stack<int> s;
    s.push(l);
    s.push(h);

    while (!s.empty()){
        h = s.top();
        s.pop();
        l = s.top();
        s.pop();

        int pivot = partition(l, h);
        if (pivot - 1 > l){
            s.push(l);
            s.push(pivot -1);
        }
        if (pivot + 1 < h){
            s.push(pivot + 1);
            s.push(h);
        }
    }
}


int main(){
    A = {20, 12, 9, 8, 7 , 4, 3, 1};
    N = A.size();
    display(A);
    quickSortIter(0, N -1);
    display(A);
    return 0;
}
