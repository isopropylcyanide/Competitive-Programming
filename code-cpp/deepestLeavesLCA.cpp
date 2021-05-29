#include <iostream>
#include <map>
#include <cmath>
#include <cstring>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int max(int first, int second);

std::map<TreeNode *, int> depth;

int calculateDepths(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    //path compression
    if (depth.find(root) != depth.end()) {
        return depth[root];
    }
    int depthLeft = calculateDepths(root->left);
    int depthRight = calculateDepths(root->right);
    int depthHere = 1 + max(depthLeft, depthRight);
    depth[root] = depthHere;
    return depthHere;
}

int max(int first, int second) {
    return first > second ? first : second;
}

int getDepth(TreeNode *node) {
    if (depth.find(node) == depth.end()) {
        return 0;
    }
    return depth[node];
}

TreeNode *lcaDeepestLeavesUtil(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }
    int depthLeft = getDepth(root->left);
    int depthRight = getDepth(root->right);
    if (depthLeft == depthRight) {
        return root;
    }
    if (depthLeft > depthRight) {
        //lies in left
        return lcaDeepestLeavesUtil(root->left);
    } else {
        return lcaDeepestLeavesUtil(root->right);
    }
}

TreeNode *lcaDeepestLeaves(TreeNode *root) {
    calculateDepths(root);
    return lcaDeepestLeavesUtil(root);
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode *deepest = lcaDeepestLeaves(root);
    std::cout << "Deepest: " << deepest->val << std::endl;
    return 0;
}