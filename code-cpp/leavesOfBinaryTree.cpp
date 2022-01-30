#include <bits/stdc++.h>

/*
 * Given a binary tree, find the lowest common ancestor (LCA) of all the given nodes in the tree.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct result {
    bool isCollected; // whether collection happened or not
    int generationId; // the generation ID which it was collected under (if collected)
    result(bool isCollected, int generationId) : isCollected(isCollected), generationId(generationId) {}
};

result traverse(TreeNode *root, int collectionGeneration, map<int, vector<int>> &leaves) {
    if (root == NULL) {
        return result(false, collectionGeneration); // nothing is collected
    }
    if (root->left == NULL && root->right == NULL) {
        leaves[collectionGeneration].push_back(root->val); // this is a leaf and we should collect it
        return result(true, collectionGeneration);
    }

    result sceneOnLeft = traverse(root->left, collectionGeneration, leaves);
    result sceneOnRight = traverse(root->right, collectionGeneration, leaves);

    // now that we know the scene on both left and right, let's use this to decide what happens to "this" node
    if (sceneOnLeft.isCollected &&
        sceneOnRight.isCollected) { // both children are collected, so this should be too and links should be removed
        root->left = NULL;
        root->right = NULL;
        collectionGeneration = max(sceneOnRight.generationId, sceneOnLeft.generationId) +
                               1; // the new generation ID is the maximum of whatever was collected from left/right
        leaves[collectionGeneration].push_back(root->val);
        return result(true, collectionGeneration);

    } else if (sceneOnLeft.isCollected) { // only left child is collected, so we need to unlink
        root->left = NULL;
        if (root->right == NULL) { // if the right node is null, then we can call it a leaf
            collectionGeneration = sceneOnLeft.generationId + 1; // next generation
            leaves[collectionGeneration].push_back(root->val); // collect this
            return result(true, collectionGeneration);
        }
        return result(false, sceneOnLeft.generationId);

    } else if (sceneOnRight.isCollected) { // do the exact same thing for right
        root->right = NULL;
        if (root->left == NULL) {
            collectionGeneration = sceneOnRight.generationId + 1;
            leaves[collectionGeneration].push_back(root->val);
            return result(true, collectionGeneration);
        }
        return result(false, sceneOnRight.generationId);
    }
    return result(false, collectionGeneration);
}

vector <vector<int>> findLeaves(TreeNode *root) {
    /*
     * The core idea is that we are at any given node during our traversal journey, if it happens to be a leaf node, we need to do a few things
        - We need to collect this node (because the questions asks us to).
        - Second, we need to break the tie with our parent and signal to it that we are collected
     */
    vector <vector<int>> leaves;
    map<int, vector<int>> generationCollectionLeaves;
    traverse(root, 0, generationCollectionLeaves);
    for (auto&[k, v]: generationCollectionLeaves) {
        leaves.push_back(v);
    }
    return leaves;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right = new TreeNode(3);

    vector <vector<int>> leaves = findLeaves(root);
    for (auto vs : leaves) {
        if (!vs.empty()) {
            for (auto v: vs) {
                cout << v << " -> ";
            }
            cout << endl;
        }
    }
    return 0;
}
