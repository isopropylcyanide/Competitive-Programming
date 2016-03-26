#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &H, int i){
    int left = 2*i + 1, right = 2*i + 2;
    int smallest = i;
    smallest = (left < H.size() && H[left] < H[i]) ? left : i;
    smallest = (right < H.size() && H[right] < H[smallest]) ? right : smallest;

    if (smallest != i){
        swap(H[i], H[smallest]);
        heapify(H, smallest);
    }
}

vector<int> buildHeap(vector<int> &A){
    vector<int> H(A);
    for (int i = A.size()/2; i >= 0; i--)
        heapify(H, i);

    return H;
}

int main(){
    vector<int> A;
    string line;
    int c;
    getline(cin, line);
    istringstream iss(line);
    while (iss >> c)
        A.push_back(c);

    vector<int> H = buildHeap(A);
    cout << *H.begin();
    // make_heap(A.begin(), A.end(), greater<int>());
    // cout << *A.begin();

    return 0;
}
