#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>

using namespace std;

/**
 * Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
 * There may be multiple nodes in the same row and same column.
 * In such a case, sort these nodes by their values.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode *node, int distance, int depth, map<int, map<int, vector<int>>> &distDepthQueue) {
    // keep track of the current distance as well as the depth
    // the node with a greater depth needs to sink in the queue
    // but if two nodes are at the same height, we need to pick the left first
    if (node == NULL) {
        return;
    }
    distDepthQueue[distance][depth].push_back(node->val);
    traverse(node->left, distance - 1, depth + 1, distDepthQueue);
    traverse(node->right, distance + 1, depth + 1, distDepthQueue);
}

vector<vector<int>> verticalTraversal(TreeNode *root) {
    vector<vector<int>> order;
    map<int, map<int, vector<int>>> distToDepthQueue;
    // given that maps are ordered, we can use this to push both distance and depth

    traverse(root, 0, 0, distToDepthQueue);
    for (auto&[dist, depthOrdered] : distToDepthQueue) {
        // map iterates in smallest distance first manner
        if (depthOrdered.size() != 0) {
            vector<int> values;
            for (auto&[depth, sameDepthItems] : depthOrdered) {
                // same distance and same depth, order them using sort
                vector<int> sorted;
                for (auto val: sameDepthItems) {
                    sorted.push_back(val);
                }
                sort(sorted.begin(), sorted.end());
                values.insert(values.end(), sorted.begin(), sorted.end());
            }
            order.push_back(values);
        }
    }
    return order;
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(7);

    vector<vector<int>> order = verticalTraversal(root);
    for (auto vs : order) {
        for (auto v: vs) {
            cout << v << " -> ";
        }
        cout << endl;
    }
    return 0;
}

