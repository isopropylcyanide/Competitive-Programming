#include <bits/stdc++.h>

/*
 * Given a binary search tree, find the lowest common ancestor (LCA) of two given nodes
 * in the tree.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ostream& operator<<(ostream& c, deque<TreeNode*>& queue) {
    deque<TreeNode*> q(queue);
    while (!q.empty()) {
        c << " -> " << q.front()->val;
        q.pop_front();
    }
    c << std::endl;
    return c;
}

bool dfs(TreeNode* node, TreeNode* target, deque<TreeNode*>& parents) {
    if (node == NULL) {
        return false;
    }
    if (node == target) {
        //note this
        parents.push_front(node);
        return true;
    }
    bool foundLeft = dfs(node->left, target, parents);
    bool foundRight = dfs(node->right, target, parents);
    if (foundLeft) {
        //push parent and signal we found it
        parents.push_front(node);
        return true;
    } else if (foundRight) {
        //push parent and signal we found it.
        parents.push_front(node);
        return true;
    } else {
        //we neither found it in left or right tree
        //this works only because vals are unique
        return false;
    }
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //use properties of BST
    if (root == NULL) {
        return NULL;
    }
    int nodeVal = root->val;
    int pVal = p->val;
    int qVal = q->val;
    if (pVal < nodeVal && qVal < nodeVal) {
        //LCA is in the left subtree
        return lowestCommonAncestor(root->left, p, q);
    }
    if (pVal > nodeVal && qVal > nodeVal) {
        //LCA is in the right subtree
        return lowestCommonAncestor(root->right, p, q);
    }
    if ((pVal <= nodeVal && qVal >= nodeVal) || (qVal <= nodeVal && pVal >= nodeVal)) {
        //current node is where things bifurcate
        return root;
    }
    return NULL;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    std::cout << lowestCommonAncestor(root, root->left->right->left, root->right->right)->val << std::endl;
    std::cout << lowestCommonAncestor(root, root->left->right->left, root->left)->val << std::endl;
    std::cout << lowestCommonAncestor(root, root->left->right->left, root)->val << std::endl;
    std::cout << lowestCommonAncestor(root, root->left->right->left, root->left->right->right)->val << std::endl;
    return 0;
}
