#include <iostream>

using namespace std;

/*
 * Given the root of a binary search tree and a node p in it, return the in-order successor
 * of that node in the BST. If there's none, return null
 * You will have direct access to the node but not to the root of the tree.
 * Each node will have a reference to its parent node.
 */

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *parent;

    Node(int val) : val(val) {}

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

Node *inorderSuccessor(Node *node) {
    if (!node) {
        return NULL;
    }
    // if node has a right child, it's the leftmost item in the right child
    if (node->right) {
        Node *successor = node->right;
        while (successor->left) {
            successor = successor->left;
        }
        return successor;
    }
    // if node doesn't have a right child, successor could be ancestor or another tree
    // we need to do an inorder traversal

    Node *current = node;
    while (current->parent != NULL && current->parent->right == current) {
        current = current->parent;
    }
    return current->parent;
}


int main() {
    Node *root = new Node(5);
    root->NodeLeft(3);
    root->left->NodeLeft(2);
    root->left->NodeRight(4);
    root->left->left->NodeLeft(1);

    root->NodeRight(6);

    std::cout << inorderSuccessor(root->left->right)->val << std::endl;
    return 0;
}
