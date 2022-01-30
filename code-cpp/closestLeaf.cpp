#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 * Given the root of a binary tree where every node has a unique value and a target integer k,\
 * return the value of the nearest leaf node to the target k in the tree.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findClosestLeaf(TreeNode *root, int k) {
    // idea is to do a DFS, build a graph, find the target node and then do a BFS
    unordered_map<TreeNode *, vector<TreeNode *>> g;
    TreeNode *target = NULL;

    // implicit lambda function
    function<void(TreeNode *, TreeNode *)> dfs = [&](TreeNode *root, TreeNode *parent) {
        if (!root) {
            return;
        }
        if (root->val == k) {
            target = root;
        }
        if (parent) { // define back edges
            g[parent].push_back(root);
            g[root].push_back(parent);
        }
        dfs(root->left, root);
        dfs(root->right, root);
    };

    dfs(root, NULL);

    // now do a BFS
    queue<TreeNode *> q;
    q.push(target);
    unordered_set<TreeNode *> seen;

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        // if this is a leaf, must be the closest
        if (node->left == NULL && node->right == NULL) {
            return node->val; // first leaf
        }
        seen.insert(node);
        for (auto child: g[node]) {
            if (seen.find(child) == seen.end()) {
                q.push(child);
            }
        }
    }
    return root->val;
}

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(6);
    std::cout << findClosestLeaf(root, root->left->val) << std::endl; // should be 4
    return 0;
}
