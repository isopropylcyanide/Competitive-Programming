#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int longest = 0;

void longestConsecutive(TreeNode *child, TreeNode *parent, int length) {
    if (child == NULL) {
        return;
    }
    if (parent != NULL && parent->val + 1 == child->val) {
        length = length + 1;
    } else {
        length = 1;
    }
    longest = max(longest, length);
    longestConsecutive(child->left, child, length);
    longestConsecutive(child->right, child, length);
}

int longestConsecutive(TreeNode *root) {
    longestConsecutive(root, NULL, 0);
    return longest;
}


int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);


//    [1,null,3,2,4,null,null,null,5]
    std::cout << "Longest consecutive path " << longestConsecutive(root) << endl;
    return 0;
}