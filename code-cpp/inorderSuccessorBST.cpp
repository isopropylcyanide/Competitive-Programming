#include <iostream>

using namespace std;

/*
 * Given the root of a binary search tree and a node p in it, return the in-order successor
 * of that node in the BST. If there's none, return null
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    // next largest for p
    if (root == NULL) {
        return NULL;
    }
    if (root->val <= p->val) {// successor has to be in right tree,
        return inorderSuccessor(root->right, p);
    } else {
        // successor is somewhere in left subtree, potentially this node if left is null
        TreeNode *left = inorderSuccessor(root->left, p);
        if (left != NULL) {
            return left;
        }
        return root;
    }
}

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(6);
    std::cout << inorderSuccessor(root, root->left->right)->val << std::endl;
    return 0;
}
