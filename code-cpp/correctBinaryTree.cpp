#include <bits/stdc++.h>

/*
 * Given an undirected tree, return its diameter: the number of edges in a 
 * longest path in that tree.
 */
typedef pair<int, int> pii;

template <typename T>
ostream &operator<<(ostream &c, vector<T> &vs) {
    for (auto v : vs) {
        c << v << " -> ";
    }
    c << std::endl;
    return c;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void getInorder(TreeNode *root, vector<int> &out) {
    if (root) {
        getInorder(root->left, out);
        out.push_back(root->val);
        // std::cout << root->val << " -> ";
        getInorder(root->right, out);
    }
}

void dropSubTree(TreeNode *root, TreeNode *parent, bool left, int offendingNode) {
    if (root) {
        if (root->val == offendingNode) {
            if (left) {
                //this node is left to parent node
                parent->left = NULL;
                return;
            } else {
                //this node is right to parent
                parent->right = NULL;
                return;
            }
        }
        //else try in both left and right places
        dropSubTree(root->left, root, true, offendingNode);
        dropSubTree(root->right, root, false, offendingNode);
    }
}

TreeNode *correctBinaryTreeSpace(TreeNode *root) {
    //messedUpInorder
    vector<int> out;
    getInorder(root, out);

    std::cout << out << endl;
    map<int, int> numIndex;
    int offendingValue = -1;
    //whichever index you find a previous element
    for (int i = 0; i < out.size(); i++) {
        if (numIndex.find(out[i]) != numIndex.end()) {
            int seenIndex = numIndex[out[i]];
            offendingValue = out[seenIndex - 1];
            break;
        }
        numIndex[out[i]] = i;
    }
    TreeNode *rootCopy = root;
    dropSubTree(root, NULL, true, offendingValue);
    return rootCopy;
}

set<int> visited;

TreeNode *correctBinaryTree(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->right != NULL && visited.find(root->right->val) != visited.end()) {
        return NULL;
    }
    visited.insert(root->val);
    root->right = correctBinaryTree(root->right);
    root->left = correctBinaryTree(root->left);
    return root;
}

void printInorder(TreeNode *root) {
    if (root) {
        printInorder(root->left);
        std::cout << root->val << " -> ";
        printInorder(root->right);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(7);
    root->left->left->left = new TreeNode(2);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(6);

    printInorder(root);
    std::cout << endl;

    root->left->left->right = root->right->right;
    printInorder(root);
    std::cout << endl;

    std::cout << "Correcting binary tree\n";
    correctBinaryTree(root);

    printInorder(root);
    std::cout << endl;
    return 0;
}
