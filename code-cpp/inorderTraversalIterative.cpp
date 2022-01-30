#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> out;
    stack<TreeNode *> s;

    TreeNode *current = root;
    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        out.push_back(current->val);
        current = current->right;
    }
    return out;
}

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(6);
    vector<int> vs = inorderTraversal(root);
    for (auto v: vs) {
        std::cout << v << " -> ";
    }
    std::cout << endl;
    return 0;
}
