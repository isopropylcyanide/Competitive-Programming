#include <bits/stdc++.h>

/*
 * Given the root of a binary tree, return the maximum path sum of any path.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * So the idea is that each node carries 4 sum. These indicate the state of the 
 * max unique path sum rooted at a particular node. 
 * 
 * A path is joinable if it can be extended by its parents. Because every node
 * has to be traversed only once a path is either joinable or not.
 * - Node
 * - Node + joinable best in either left or right :: joinable
 * - Node + lefts's joinable best + right's joinable best :: non joinable
 * - Best Subtree sum stored under current node
 * 
 * At the end, we return the best subtree sum found under the original root.
*/

typedef struct PathSum {
    //node's value in isolation
    int node;

    //node's value in combination with the best in either left or right subtree
    int nodeJoinable;

    //node's value + left's joinable best + right's joinable best
    int nodeNonJoinable;

    //best sum found so far rooted under all subtrees of this node
    int nodeSubtreeBest;

    PathSum(int a, int b, int c, int d) {
        node = a;
        nodeJoinable = b;
        nodeNonJoinable = c;
        nodeSubtreeBest = d;
    }
} PathSum;

ostream& operator<<(ostream& c, const PathSum& p) {
    c << "{ Node = " << p.node << " , joinable: " << p.nodeJoinable;
    c << " , nonJoinable: " << p.nodeNonJoinable;
    c << " , nodeSubtreeBest: " << p.nodeSubtreeBest;
    c << std::endl;
    return c;
}

int max_(int a, int b, int c, int d, int e) {
    return max(e, max(max(a, b), max(c, d)));
}

PathSum dfsPathSum(TreeNode* node) {
    if (node == NULL) {
        return PathSum(0, 0, 0, INT_MIN);
    }
    PathSum leftSum = dfsPathSum(node->left);
    PathSum rightSum = dfsPathSum(node->right);

    int nodePathSum = node->val;
    //If you were this node with either the left or right, what do you get?
    int nodeJoinableSum = max(node->val, node->val + max(leftSum.nodeJoinable, rightSum.nodeJoinable));

    //If you joined this node with its left and right subtrees what do you get?
    int nodeNonJoinableSum = node->val + leftSum.nodeJoinable + rightSum.nodeJoinable;

    int nodeBestSubtreeSum = max_(
        leftSum.nodeSubtreeBest,
        rightSum.nodeSubtreeBest,
        nodeJoinableSum,
        nodeNonJoinableSum,
        nodePathSum);

    PathSum p = PathSum(nodePathSum, nodeJoinableSum, nodeNonJoinableSum, nodeBestSubtreeSum);
    std::cout << "At node: " << node->val << p;
    return p;
}

int maxPathSum(TreeNode* root) {
    return dfsPathSum(root).nodeSubtreeBest;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // TreeNode* root = new TreeNode(-2);
    // root->left = new TreeNode(9);

    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);
    // std::cout << maxPathSum(root) << std::endl;

    // TreeNode* root = new TreeNode(2);
    // root->left = new TreeNode(-1);
    // root->right = new TreeNode(-2);
    // TreeNode* root = new TreeNode(6);
    // root->left = new TreeNode(2);
    // root->left->left = new TreeNode(0);
    // root->left->right = new TreeNode(4);
    // root->left->right->left = new TreeNode(3);
    // root->left->right->right = new TreeNode(5);

    // root->right = new TreeNode(8);
    // root->right->left = new TreeNode(7);
    // root->right->right = new TreeNode(9);
    // TreeNode* root = new TreeNode(6);
    // root->left = new TreeNode(2);
    // root->left->left = new TreeNode(0);
    // root->left->right = new TreeNode(4);
    // root->left->right->left = new TreeNode(3);
    // root->left->right->right = new TreeNode(5);

    // root->right = new TreeNode(8);
    // root->right->left = new TreeNode(7);
    // root->right->right = new TreeNode(9);
    TreeNode* root = new TreeNode(9);
    root->left = new TreeNode(6);
    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(2);
    root->right->right->left = new TreeNode(2);
    root->right->right->left->left = new TreeNode(-6);
    root->right->right->left->left->left = new TreeNode(-6);
    root->right->right->left->right = new TreeNode(-6);

    std::cout << maxPathSum(root) << std::endl;
    return 0;
}
