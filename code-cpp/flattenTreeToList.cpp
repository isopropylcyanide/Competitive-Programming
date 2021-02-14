#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *f(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        return root;
    }
    TreeNode *leftTail = f(root->left);
    TreeNode *rightTail = f(root->right);
    //both left and right are flattened..now we need to join them
    if (leftTail) {
        leftTail->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    return rightTail == NULL ? leftTail : rightTail;
}

void flatten(TreeNode *root) {
    f(root);
}

int main() {
    return 0;
}