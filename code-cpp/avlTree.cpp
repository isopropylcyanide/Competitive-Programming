#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct node{
        int val;    //value
         node* left; //left child
         node* right; //right child
        int ht;     //ht of the node
} node;


void preOrder(node * root){
    if (!root)
    return;
    cout<<" "<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


node * newNode(int val){
    node * newNode = new node();
    newNode -> val = val;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> ht = 1;
    return newNode;
}



// A utility function to get height of the tree
int ht(node *N){
    if (N == NULL)
        return 0;
    return N->ht;
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
 node *rightRotate( node *y){
     node *x = y->left;
     node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update hts
    y->ht = max(ht(y->left), ht(y->right))+1;
    x->ht = max(ht(x->left), ht(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
 node *leftRotate(node *x){
     node *y = x->right;
     node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update hts
    x->ht = max(ht(x->left), ht(x->right))+1;
    y->ht = max(ht(y->left), ht(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance( node *N){
    if (N == NULL)
        return 0;
    return ht(N->left) - ht(N->right);
}


node *insert(node * root, int new_val){
    if (!root){
        root = newNode(new_val);
        return root;
    }

    else if (root -> val < new_val)
        root->right = insert(root->right, new_val);

    else if (root -> val > new_val)
        root->left =  insert(root->left, new_val);

    /* 2. Update ht of this ancestor node */
    root->ht = max(ht(root->left), ht(root->right)) + 1;

    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && new_val < root ->left->val)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && new_val > root->right->val)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && new_val > root->left->val){
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && new_val < root->right-> val){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    /* return the (unchanged) node pointer */
    return root;
}

int main(){
    node * root = NULL;
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);

    preOrder(root);

    return 0;
}
