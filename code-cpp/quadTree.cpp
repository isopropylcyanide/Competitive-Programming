#include <bits/stdc++.h>

/**
 * Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.
*/

class Node {
   public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node* f(int x, int y, int length, vector<vector<int>>& grid) {
    if (length == 1) {
        //leaf node
        Node* result = new Node(grid[x][y] != 0, 1);
        return result;
    }
    Node* result = new Node();
    Node* topLeft = f(x, y, length / 2, grid);
    Node* topRight = f(x, y + length / 2, length / 2, grid);
    Node* bottomLeft = f(x + length / 2, y, length / 2, grid);
    Node* bottomRight = f(x + length / 2, y + length / 2, length / 2, grid);

    if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
        result->isLeaf = true;
        result->val = topLeft->val;
    } else {
        result->topLeft = topLeft;
        result->topRight = topRight;
        result->bottomLeft = bottomLeft;
        result->bottomRight = bottomRight;
    }
    //during merge, if it works out, discard the smaller trees and create bigger ones
    return result;
}

Node* construct(vector<vector<int>>& grid) {
    int n = grid.size();
    // Node* root = f(mp(0, 0), mp(0, n - 1), mp(n - 1, 0), mp(n - 1, n - 1));
    return f(0, 0, n, grid);

    // return root;
    //0, 0, and n - 1, n - 1

    //segment is merged
    //LT, LR, BT, BR::if combined sum = 4 * cell in each, then valid and isLeaf

    //efficient way to compute number of 1's and 0's in a range
}

int main() {
    vector<vector<int>> grid = {
        {1, 1},
        {1, 0}};

    Node* root = construct(grid);
    return 0;
}