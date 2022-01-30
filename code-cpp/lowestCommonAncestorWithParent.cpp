#include <bits/stdc++.h>

/*
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * Parent information is available against each node
 */

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *parent;

    Node(int val, Node *parent) : val(val), parent(parent) {}

    void NodeLeft(int value) {
        Node *pNode = new Node(value, this);
        this->left = pNode;
    }

    void NodeRight(int value) {
        Node *pNode = new Node(value, this);
        this->right = pNode;
    }
};

Node *lowestCommonAncestor(Node *p, Node *q) {
    Node *pPar = p;
    Node *qPar = q;
    while (pPar != qPar) {
        pPar = pPar == nullptr ? q : pPar->parent;
        qPar = qPar == nullptr ? p : qPar->parent;
    }
    return pPar;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Node *root = new Node(3, nullptr);
    root->NodeLeft(5);
    root->left->NodeLeft(6);
    root->left->NodeRight(2);
    root->left->right->NodeLeft(7);
    root->left->right->NodeRight(4);

    root->NodeRight(1);
    root->right->NodeLeft(0);
    root->right->NodeRight(8);

    // 5 4 = 5
    std::cout << lowestCommonAncestor(root->left, root->left->right->right)->val << std::endl;

    // 7 4 = 2
    std::cout << lowestCommonAncestor(root->left->right->left, root->left->right->right)->val << std::endl;

    // 7 8 = 3
    std::cout << lowestCommonAncestor(root->left->right->left, root->right->right)->val << std::endl;

    // 3 5 = 3
    std::cout << lowestCommonAncestor(root->right, root)->val << std::endl;
    return 0;
}
