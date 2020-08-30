#include <bits/stdc++.h>
using namespace std;

vector<int> A, B;

// Returns sum of A[0..index] (Range Sum)
int pointSum(int index){
    int sum = 0;
    index = index + 1;
    while (index > 0){
        sum += B[index];
        index -= index & (-index);
    }
    return sum;
}

int rangeSum(int l, int r){
    return pointSum(r) - pointSum(l -1);
}

// Updates a node in Binary Index Tree (B)
void pointUpdate(int index, int val){
    index = index + 1;
    while (index <= B.size()){
       B[index] += val;
       index += index & (-index);
    }
}

// Updates A[l..r] by val
void rangeUpdate(int l, int r, int val){
    pointUpdate(l, val);
    pointUpdate(r + 1, -val);
}

// Constructs and returns a Binary Indexed Tree for given array of size n.
void constructBITree(vector<int> &A, int n){
    B.resize(n + 1, 0);
    for (int i = 0; i < n; i++)
        pointUpdate(i, A[i]);
}

int main(){
    A = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto a : A)
        cout << a << " -> ";
    cout << endl;


    constructBITree(A, A.size());
    cout << "\nSum of elements in A[0..5] is " << pointSum(5);

    cout << "\n SUm from 3 to 7: " << rangeSum(3, 7) << endl;
    cout << "\n Now rangeUpdate 3 to 7 by 4\n";
    rangeUpdate(3, 7, 4);
    cout << "\n SUm from 3 to 7: " << rangeSum(3, 7) << endl;

    // Let use test the update operation
    A[3] += 6;
    pointUpdate(3, 6); //Update BIT for above change in A[]

    cout << "\nSum of elements in A[0..5] after update is " << pointSum(3);

    return 0;
}
