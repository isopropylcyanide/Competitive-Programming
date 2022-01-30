#include <bits/stdc++.h>

/*
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
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
    return p;
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

    std::cout << lowestCommonAncestor(root->left, root->left->right->right)->val << std::endl;
    return 0;
}
