#include <bits/stdc++.h>
using namespace std;

/*Print a line by line level order traversal*/

struct Tree {
    int val;
    Tree *left, *right, *next;
    Tree(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void levelOrd(Tree* A) {
    //levelOrd next pointers.
    queue<Tree*> q;
    if (!A || (!(A->left) && !(A->right)))
        return;

    q.push(A);
    q.push(NULL);  //insert null marker initially for the root
    Tree* cur = NULL;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur == NULL) {
            //if we received a NULL marker, then it signifies end of the level
            cout << endl;
            if (!q.empty())
                q.push(NULL);  //don't forget to push NULL again
            continue;
        }
        cout << cur->val << " ";
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
}

template <typename T>
ostream& operator<<(ostream& c, vector<T>& vec) {
    for (auto t : vec) {
        c << t << ' ';
    }
    return c;
}

template <typename T>
ostream& operator<<(ostream& c, vector<vector<T>>& vec) {
    for (auto t : vec) {
        c << t << ' ';
        c << std::endl;
    }
    return c;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) {
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    vector<int> currentLevel;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node == NULL) {
            //marker
            ans.push_back(currentLevel);
            currentLevel.clear();
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            currentLevel.push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
    return ans;
}

int main() {
    /*
                1
              /   \
             2     3
            / \   /  \
           4   5 6    7
    */
    TreeNode* t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);
    t->left->left = new TreeNode(4);
    t->left->right = new TreeNode(5);
    t->right->left = new TreeNode(6);
    t->right->right = new TreeNode(7);

    // levelOrd(t);
    vector<vector<int>> order = levelOrder(t);
    std::cout << order << endl;
    return 0;
}
