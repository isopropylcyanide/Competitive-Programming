#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
// Demonstrate Segment Trees in C++
// Perform a range minimum query given an input vector
vi stMin, stMax;

void constSegMinUtil(vi &inp, int pos, int low, int high, vi & st){
    // Utility method for the seg tree construction for range min query
    assert(low <= high);
    if (low == high){    //reached a leaf node
        st[pos] = inp[low];
        return;
    }
    else{ //descend into the left tree and fill the values
        int mid = (low + high) /2;
        constSegMinUtil(inp, 2 * pos + 1, low, mid, st);       //left child
        constSegMinUtil(inp, 2 * pos + 2, mid +1, high, st);   //right child
        st[pos] = min(st[2 * pos +1], st[2 * pos + 2]);
    }
}
void constSegMaxUtil(vi &inp, int pos, int low, int high, vi & st){
    // Utility method for the seg tree construction for range Max query
    assert(low <= high);
    if (low == high){    //reached a leaf node
        st[pos] = inp[low];
        return;
    }
    else{ //descend into the left tree and fill the values
        int mid = (low + high) /2;
        constSegMaxUtil(inp, 2 * pos + 1, low, mid, st);       //left child
        constSegMaxUtil(inp, 2 * pos + 2, mid +1, high, st);   //right child
        st[pos] = max(st[2 * pos +1], st[2 * pos + 2]);
    }
}

void constSegTree(vi &A, bool minimum){
    // COnstructs a seg tree given a vector A
    int sizeSegTree =  pow(2, int(ceil(log2(A.size())))) * 2 -1;
    if (minimum){
        stMin.resize(sizeSegTree, INT_MAX);
        constSegMinUtil(A, 0, 0, A.size() -1, stMin);
    }
    else{
        stMax.resize(sizeSegTree, INT_MIN);
        constSegMaxUtil(A, 0, 0, A.size() -1, stMax);
    }
}

int rMinQUtil(int qL,int  qH, int l, int  h, int pos){
    // Utility function that, given a range calculates the minimum in that range
    if (qL > h || qH < l) //no overlap
        return INT_MAX;
    if (qL <= l && qH >= h) //total overlap
        return stMin[pos];
    //else partial overlap
    int mid = (l + h) /2;
    return min(rMinQUtil(qL, qH, l, mid, 2 * pos + 1),
                rMinQUtil(qL, qH, mid +1, h, 2 * pos +2));
}


int rMinQ(int qL, int qH, int n){
    // Calculates max in a range specified by qL - qH
    return rMinQUtil(qL, qH, 0, n -1, 0);
}

int rMaxQUtil(int qL,int  qH, int l, int  h, int pos){
    // Utility function that, given a range calculates the minimum in that range
    if (qL > h || qH < l) //no overlap
        return INT_MIN;
    if (qL <= l && qH >= h) //total overlap
        return stMax[pos];
    //else partial overlap
    int mid = (l + h) /2;
    return max(rMaxQUtil(qL, qH, l, mid, 2 * pos + 1),
                rMaxQUtil(qL, qH, mid +1, h, 2 * pos +2));
}


int rMaxQ(int qL, int qH, int n){
    // Calculates max in a range specified by qL - qH
    return rMaxQUtil(qL, qH, 0, n -1, 0);
}

int main(){

    vi A {-1, 3, 0, 2, 4, 1};
    constSegTree(A, true);
    constSegTree(A, false);

    for (auto a : A)
        cout << a <<  "\t ";
    cout << endl;

    for (int i = 0; i < A.size(); i++)
        cout << i << "\t ";

    int a, b;
    bool c;
    while (true){
        cout << "\n Range a - b Min: 0/ Max: 1 \t";
        cin >> a >> b >> c;
        if (!c)
            cout << rMinQ(a, b, A.size()) << endl;
        else
            cout << rMaxQ(a, b, A.size()) << endl;
    }

    return 0;
}
