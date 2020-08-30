#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

struct node{
    int data;
    struct node* left;
    struct node* right;
    int level;
};

/* Prototypes of a utility function to get the maximum
   value in inorder[start..end] */
int max(int inorder[], int strt, int end);

/* A utility function to allocate memory for a node */
struct node* newNode(int data, int level);

/* Recursive function to construct binary of size len from
   Inorder traversal inorder[]. Initial values of start and end
   should be 0 and len -1.  */
struct node* buildTree (int inorder[], int start, int end, int level){
    if (start > end)
        return NULL;

    /* Find index of the maximum element from Binary Tree */
    int i = max (inorder, start, end);

    /* Pick the maximum value and make it root */
    struct node *root = newNode(inorder[i], level);

    /* If this is the only element in inorder[start..end],
       then return it */
    if (start == end)
        return root;

    /* Using index in Inorder traversal, construct left and
       right subtress */
    root->left  = buildTree (inorder, start, i-1, level + 1);
    root->right = buildTree (inorder, i+1, end, level + 1);

    return root;
}

int max (int arr[], int strt, int end)
{
    int i, max = arr[strt], maxind = strt;
    for(i = strt+1; i <= end; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            maxind = i;
        }
    }
    return maxind;
}

struct node* newNode (int data, int level)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->level = level;

    return node;
}

void printInorder (struct node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder (node->left);

    /* then print the data of node */
    printf("%d (%d) ", node->data, node->level);

    /* now recur on right child */
    printInorder (node->right);
}

int main(){
    int testcases;
    llu N;
    cin >> testcases;

    while (testcases --){
        cin >> N;
        //if N + 1 is not a power of two then, tree ain't possible
        if (((N + 1) & N ) != 0){
            cout << -1 << endl;
            continue;
        }

        int A[N];
        for(int i = 0; i < N; i ++)
            cin >> A[i];

        struct node* root = buildTree(A, 0, N - 1, 1);
        printInorder(root);
    }


    return 0;
}

















//
