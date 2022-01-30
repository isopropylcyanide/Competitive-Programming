#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>

using namespace std;

/**
 * Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct depthVal {
    int depth;
    int parentDistance;
    int val;

    depthVal(int depth, int parentDistance, int val) : depth(depth), parentDistance(parentDistance), val(val) {}
};

struct compareDepth {
    bool operator()(depthVal &a, depthVal &b) {
        // return true if a is ordered before b
        if (a.depth < b.depth) {
            return true;
        }
        if (a.depth == b.depth) {
            // if both parents have same distance, the one
            return a.parentDistance < b.parentDistance;
        }
        return false;
    }
};

typedef priority_queue<depthVal, vector<depthVal>, compareDepth> depthQueue;

void traverse(TreeNode *node, int distance, int parentDistance, int depth, map<int, depthQueue> &distDepthQueue) {
    // keep track of the current distance as well as the depth
    // the node with a greater depth needs to sink in the queue
    // but if two nodes are at the same height, we need to pick the left first
    // we can do this by keeping track of the distance of its parents, left node's parent distance 
    // would be lesser than the right node's parent distance
    if (node == NULL) {
        return;
    }
    depthVal *pVal = new depthVal(depth, parentDistance, node->val);
    distDepthQueue[distance].push(*pVal);

    traverse(node->left, distance - 1, distance, depth + 1, distDepthQueue);
    traverse(node->right, distance + 1, distance, depth + 1, distDepthQueue);
}


vector<vector<int>> verticalOrder(TreeNode *root) {
    vector<vector<int>> order;
    // given that max nodes are 100, the max height is of a skewed tree
    map<int, depthQueue> distToDepthQueue;

    traverse(root, 0, 0, 0, distToDepthQueue);
    for (auto&[k, v] : distToDepthQueue) {
        if (v.size() != 0) {
            // drain queue in the order of higher depth first
            vector<int> values;
            while (!v.empty()) {
                values.push_back(v.top().val);
                v.pop();
            }
            reverse(values.begin(), values.end());
            order.push_back(values);
        }
    }
    return order;
}

void printVerticalOrder(TreeNode *root) {
    vector<vector<int>> order = verticalOrder(root);
    for (auto vs : order) {
        for (auto v: vs) {
            cout << v << " -> ";
        }
        cout << endl;
    }
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(0);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(7);

    printVerticalOrder(root);
    return 0;
}

