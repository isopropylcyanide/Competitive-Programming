#include <bits/stdc++.h>

/*
 * Given a binary tree, find the lowest common ancestor (LCA) of all the given nodes in the tree.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ostream &operator<<(ostream &c, deque<TreeNode *> &queue) {
    deque < TreeNode * > q(queue);
    while (!q.empty()) {
        c << " -> " << q.front()->val;
        q.pop_front();
    }
    c << std::endl;
    return c;
}

TreeNode *traverse(TreeNode *root, set<TreeNode *> &nodes) {
    if (root == NULL) {
        return NULL;
    }
    if (nodes.contains(root)) {
        return root;
    }
    TreeNode *left = traverse(root->left, nodes);
    TreeNode *right = traverse(root->right, nodes);
    if (left && right) {
        // all nodes were found
        return root;
    }
    return left != NULL ? left : right;
}

TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes) {
    // convert vector into set without copying
    set < TreeNode * > nodeSet(make_move_iterator(nodes.begin()), make_move_iterator(nodes.end()));
    return traverse(root, nodeSet);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    vector < TreeNode * > nodes{root->left->right->left, root->left->left, root->left->right, root->left->right->right};
    std::cout << lowestCommonAncestor(root, nodes)->val << std::endl;
    return 0;
}
