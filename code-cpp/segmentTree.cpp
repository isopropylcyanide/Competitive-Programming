#include <bits/stdc++.h>
using namespace std;

// Demonstrate Segment Trees in C++
// Perform a range minimum query given an input vector
vector<int>  stMin, stMax, stSum;

/********************************RANGE MIN SEGMENT TREE***************************/
void constSegMinUtil(vector<int>  &inp, int pos, int low, int high, vector<int>  & st){
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

void constSegMinTree(vector<int>  &A){
    // COnstructs a seg tree given a vector A
    int sizeSegTree =  pow(2, int(ceil(log2(A.size())))) * 2 -1;
    stMin.resize(sizeSegTree, INT_MAX);
    constSegMinUtil(A, 0, 0, A.size() -1, stMin);
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
/********************************RANGE MIN SEGMENT TREE***************************/


/********************************RANGE MAX SEGMENT TREE***************************/
void constSegMaxUtil(vector<int>  &inp, int pos, int low, int high, vector<int>  & st){
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

void constSegMaxTree(vector<int>  &A){
    // COnstructs a seg tree given a vector A
    int sizeSegTree =  pow(2, int(ceil(log2(A.size())))) * 2 -1;
    stMax.resize(sizeSegTree, INT_MIN);
    constSegMaxUtil(A, 0, 0, A.size() -1, stMax);
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
/********************************RANGE MAX SEGMENT TREE***************************/



/********************************SUM SEGMENT TREE***************************/
void constSegSumUtil(vector<int>  &inp, int pos, int low, int high, vector<int>  & st){
    // Utility method for the seg tree construction for range sum query
    assert(low <= high);
    if (low == high){    //reached a leaf node
        st[pos] = inp[low];
        return;
    }
    else{ //descend into the left tree and fill the values
        int mid = (low + high) /2;
        constSegSumUtil(inp, 2 * pos + 1, low, mid, st);       //left child
        constSegSumUtil(inp, 2 * pos + 2, mid +1, high, st);   //right child
        st[pos] = st[2 * pos +1] + st[2 * pos + 2];
    }
}

void constSegSumTree(vector<int>  &A){
    // COnstructs a sum seg tree given a vector A
    int sizeSegTree =  pow(2, int(ceil(log2(A.size())))) * 2 -1;
    stSum.resize(sizeSegTree, 0);
    constSegSumUtil(A, 0, 0, A.size() -1, stSum);
}

int rSumQUtil(int qL,int  qH, int l, int  h, int pos){
    // Utility function that, given a range calculates the sum in that range
    if (qL > h || qH < l) //no overlap
        return 0;
    if (qL <= l && qH >= h) //total overlap
        return stSum[pos];
    //else partial overlap
    int mid = (l + h) /2;
    return rSumQUtil(qL, qH, l, mid, 2 * pos + 1) +
                rSumQUtil(qL, qH, mid +1, h, 2 * pos +2);
}

/********************************SUM SEGMENT TREE***************************/


/********************************UPDATE RANGE***************************/
void updateValueSumUtil(vector<int>  & st, int l, int r, int i, int diff, int pos){
    /* A recursive function to update the nodes which have the given
    index in their range. The following are parameters */
    if (i < l || i > r)
        return;

    st[pos] += diff;
    if (r != l){
        int mid = (l + r)/2;
        updateValueSumUtil(st, l, mid, i, diff, 2*pos + 1);
        updateValueSumUtil(st, mid+1, r, i, diff, 2*pos + 2);
        st[pos] = st[2 *pos +1] + st[2 * pos+2];
    }
}

void updateValueMaxUtil(vector<int>  & st, int l, int r, int i, int diff, int pos){
    /* A recursive function to update the nodes which have the given
    index in their range. The following are parameters */
    if (i < l || i > r)
        return;

    st[pos] += diff;
    if (r != l){
        int mid = (l + r)/2;
        updateValueMaxUtil(st, l, mid, i, diff, 2*pos + 1);
        updateValueMaxUtil(st, mid+1, r, i, diff, 2*pos + 2);
        st[pos] = max(st[2 * pos+1], st[2 * pos+2]);
    }
}

void updateValueMinUtil(vector<int>  & st, int l, int r, int i, int diff, int pos){
    /* A recursive function to update the nodes which have the given
    index in their range. The following are parameters */
    if (i < l || i > r)
        return;

    st[pos] += diff;
    if (r != l){
        int mid = (l + r)/2;
        updateValueMinUtil(st, l, mid, i, diff, 2*pos + 1);
        updateValueMinUtil(st, mid+1, r, i, diff, 2*pos + 2);
        st[pos] = min(st[2 * pos+1], st[2 * pos+2]);
    }
}

void updateValue(vector<int>  &A, int i, int new_val, int n){
    // The function to update a value in input array and segment tree.
    // It uses updateValueUtil() to update the value in segment tree
    // Check for erroneous input index
    if (i < 0 || i > n - 1)
        return;

    // Get the difference between new value and old value
    int diff = new_val - A[i];

    // Update the value in array
    A[i] = new_val;

    // Update the values of nodes in segment tree
    updateValueSumUtil(stSum, 0, n-1, i, diff, 0);  //Update SumSegment Tree
    updateValueMaxUtil(stMax, 0, n-1, i, diff, 0);  //Update MaxSegment Tree
    updateValueMinUtil(stMin, 0, n-1, i, diff, 0);  //Update MinSegment Tree
}

/********************************UPDATE RANGE***************************/

int main(){

    vector<int>  A {-1, 3, 0, 2, 4, 1};
    constSegMinTree(A);  //rangeMin segtree
    constSegMaxTree(A);  //rangeMax segtree
    constSegSumTree(A);  //rangeSu segtree

    for (auto a : A)
        cout << a <<  "\t ";
    cout << endl;

    for (int i = 0; i < A.size(); i++)
        cout << i << "\t ";

    int a, b, c;
    char choice;

    while (true){
        cout << "\n\n A: Query a - b \tMin(0)\tMax(1)\tSum(2) ";
        cout << "\n B: Update a : b \n\t";

        cin >> choice;
        if (choice == 'A'){
            cin >> a >> b >> c;
            switch (c){
                case 0:
                    cout << rMinQUtil(a, b, 0, A.size() -1, 0) << endl;
                    break;
                case 1:
                    cout << rMaxQUtil(a, b, 0, A.size() -1, 0) << endl;
                    break;
                case 2:
                    cout << rSumQUtil(a, b, 0, A.size() -1, 0) << endl;
                default:
                    break;
            }
        }
        else{
            //Update the node value at a to b
            cin >> a >> b;
            updateValue(A, a, b, A.size());
        }
    }

    return 0;
}
