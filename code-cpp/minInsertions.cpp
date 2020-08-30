#include <bits/stdc++.h>
using namespace std;

/*
Given two binary trees T1 and T2, you have to find minimum number of insertions to be done in T1 to make it structurally identical to T2. Return -1 if not possible
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int _inserts = 0;

int sizeTree(TreeNode *A){
    // Returns the size of the tree
    if (!A)
        return 0;
    return 1 + sizeTree(A -> left) + sizeTree(A -> right);
}


bool balancable(TreeNode *A, TreeNode *B){
    if (A == NULL && B == NULL)
        // Both nodes are null
        return true;

    else if (A == NULL){
        // No A, but B, so we can insert a node
        _inserts += sizeTree(B);
        return true;
    }
    else if (B == NULL){
        // No B, but A
        return false;
    }
    else{
        // both nodes are not null
        return balancable(A -> left, B -> left) && balancable(A -> right, B -> right);
    }
}


int cntMatrix(TreeNode *A, TreeNode *B) {
    // Return 1 or -1, depending on whether A can be made structurally into B
    //if both are null, then they are similar
    if (balancable(A -> left, B -> left) && balancable(A -> right, B -> right))
        return _inserts;
    return -1;
}


int main(){
    TreeNode *A = new TreeNode(10);
    A -> left = new TreeNode(9);
    A -> right = new TreeNode(20);

    TreeNode *B = new TreeNode(5);
    B -> left = new TreeNode(2);
    B -> left -> left = new TreeNode(1);
    B -> right = new TreeNode(7);
    B -> right -> left = new TreeNode(7);
    B -> right -> left = new TreeNode(6);
    B -> right -> right = new TreeNode(30);

    cout << cntMatrix(A, B) << endl;

    return 0;
}
