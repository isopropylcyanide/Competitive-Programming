#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

// Create a minHeap to sort numbers in ascending order

inline void display(vector<int> &X){
    cout << endl;
    for (auto a : X)
        cout << a << " -> ";
    cout << endl;
}

void heapify(int i, int N){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int smallest = i;

    if (left < N && A[left] < A[i])
        smallest = left;
    if (right < N && A[right] < A[smallest])
        smallest = right;

    if (smallest != i){
        swap(A[smallest], A[i]);
        heapify(smallest, N);
    }
}

void createHeap(){
    for (int i = N/2; i >= 0; i--)
        heapify(i, N);
}

void heapSort(){
    cout << "\n Sorted Array: ";
    while(N){
        cout << A[0] << " -> ";
        swap(A[0], A[N -1]);
        N -= 1;
        heapify(0, N);
    }
}

int main(){
    A = {20, 12, 9, 8, 7 , 4, 3, 1};
    N = A.size();
    createHeap();
    heapSort();

    return 0;
}
