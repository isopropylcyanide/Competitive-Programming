#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode *A) {
    //  Finds height of a tree
    if (!A)
        return 0;
    if (!(A->left) && !(A->right))
        return 1;

    int lh = 1 + height(A->left);
    int rh = 1 + height(A->right);

    if (lh < 0 || rh < 0)
        return INT_MIN;
    if (abs(lh - rh) > 1)
        return INT_MIN;
    return max(lh, rh);
}

int isBalanced(TreeNode *A) {
    //  Checks if a given tree is balanced at the root A
    if (height(A) < 0)
        return 0;
    return 1;
}

vector<int> inorderTraversal(TreeNode *A) {
    //Performs iterative inorder traversal
    vector<int> ans;
    if (!A)
        return ans;

    stack<TreeNode *> s;
    TreeNode *p = A;
    while (p) {
        s.push(p);
        p = p->left;
    }

    while (!s.empty()) {
        p = s.top();
        ans.push_back(p->val);
        s.pop();
        if (p->right) {
            p = p->right;
            while (p) {
                s.push(p);
                p = p->left;
            }
        }
    }
    return ans;
}

vector<int> postorderTraversal(TreeNode *A) {
    //Performs iterative postorder traversal
    vector<int> ans;
    if (!A)
        return ans;

    stack<TreeNode *> s;
    s.push(A);

    while (!s.empty()) {
        TreeNode *temp = s.top();
        if (!(temp->right) && !(temp->left)) {
            ans.push_back(temp->val);
            s.pop();
        } else {
            if (temp->right) {
                s.push(temp->right);
                temp->right = NULL;
            }
            if (temp->left) {
                s.push(temp->left);
                temp->left = NULL;
            }
        }
    }
    return ans;
}

vector<int> preorderTraversal(TreeNode *A) {
    //Performs iterative preorder traversal
    vector<int> ans;
    if (!A)
        return ans;

    stack<TreeNode *> s;
    s.push(A);

    while (!s.empty()) {
        TreeNode *temp = s.top();
        s.pop();
        ans.push_back(temp->val);
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
    return ans;
}

void inorder(TreeNode *p, vector<int> &V) {
    //Performs recursive inorder traversal
    if (p) {
        inorder(p->left, V);
        if (p)
            V.push_back(p->val);
        inorder(p->right, V);
    }
}

TreeNode *searchAndRef(TreeNode *A, int V) {
    // Searches a node if found and returns its reference
    if (!A)
        return NULL;
    if (A->val == V)
        return A;
    else if (A->val < V)
        return searchAndRef(A->right, V);
    else
        return searchAndRef(A->left, V);
}

TreeNode *findMin(TreeNode *t) {
    //Finds node with minimum value in a BST
    if (!t)
        return NULL;
    while (t->left)
        t = t->left;
    return t;
}

TreeNode *getSuccessor(TreeNode *A, int B) {
    //Get the next successor node in a BST
    TreeNode *cur = searchAndRef(A, B);
    if (!cur)
        return NULL;

    //there's a right subtree
    if (cur->right)
        return findMin(cur->right);

    //there's no right. Find least ancestor for which cur is in leftsubtree
    TreeNode *succ = NULL, *anc = A;
    while (anc != cur) {
        if (cur->val < anc->val) {
            succ = anc;
            anc = anc->left;
        } else
            anc = anc->right;
    }
    return succ;
}

int isValidBST(TreeNode *A) {
    // Checks is given tree is a valid BST
    vector<int> order = inorderTraversal(A);
    for (int i = 0; i < order.size() - 1; i++)
        if (order[i] > order[i + 1])
            return 0;
    return 1;
}

int isSameTree(TreeNode *A, TreeNode *B) {
    // checks if two trees are same
    if (!A && !B)
        return 1;
    else if ((A && !B) || (B && !A))
        return 0;
    else
        return A->val == B->val && isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
}

void hasPathSumUtil(TreeNode *A, int curSum, vector<vector<int>> &all, vector<int> &cur) {
    // checks if any leaf path sum amounts to B helper
    if (!A)
        return;

    int remSum = curSum - A->val;
    cur.push_back(A->val);

    if (!(A->left) && !(A->right)) {
        if (remSum == 0)
            all.push_back(cur);
        cur.pop_back();
        return;
    }

    hasPathSumUtil(A->left, curSum - A->val, all, cur);
    hasPathSumUtil(A->right, curSum - A->val, all, cur);
    cur.pop_back();
    return;
}

vector<vector<int>> pathSum(TreeNode *A, int B) {
    // checks if any leaf path sum amounts to B
    vector<vector<int>> allPaths;
    vector<int> curr;
    if (!A)
        return allPaths;
    hasPathSumUtil(A, B, allPaths, curr);
    return allPaths;
}

TreeNode *sortedArBSTUtil(const vector<int> &A, int l, int h) {
    //given a sorted array, create a BST helper
    if (l > h)
        return NULL;
    int mid = (h + l) / 2;
    TreeNode *root = new TreeNode(A[mid]);
    root->left = sortedArBSTUtil(A, l, mid - 1);
    root->right = sortedArBSTUtil(A, mid + 1, h);

    return root;
}

TreeNode *sortedArrayToBST(const vector<int> &A) {
    //given a sorted array, create a BST
    return sortedArBSTUtil(A, 0, A.size() - 1);
}

int isLeaf(TreeNode *t) {
    // returns true is node is a leaf
    return !(t->left) && !(t->right);
}

int isMirror(TreeNode *a, TreeNode *b) {
    // Given two trees, check if they are mirrors of each other
    if (!a && !b)
        return 1;
    if (a && b && a->val == b->val &&
        isMirror(a->left, b->right) && isMirror(a->right, b->left))
        return 1;
    return 0;
}

int isSymmetric(TreeNode *A) {
    // Checks if a tree is symmetric about itself
    if (isMirror(A, A))
        return 1;
    return 0;
}

int maxDepth(TreeNode *A) {
    // Find maximum depth of a tree
    if (!A)
        return 0;
    else if (!(A->left) && !(A->right))
        return 1;
    else
        return max(maxDepth(A->left), maxDepth(A->right)) + 1;
}

int minDepth(TreeNode *A) {
    // Find minimum depth of a tree
    if (!A)
        return INT_MAX;
    else if (!(A->left) && !(A->right))
        return 1;
    else
        return min(minDepth(A->left), minDepth(A->right)) + 1;
}

void printNumbersToLeaf_util(TreeNode *A, vector<int> &v, vector<vector<int>> &all) {
    // Prints numbers from root to leaf helper
    if (!A)
        return;

    if (!(A->left) && !(A->right)) {
        v.push_back(A->val);
        all.push_back(v);
    }

    v.push_back(A->val);
    vector<int> copy(v);
    printNumbersToLeaf_util(A->left, v, all);
    v = copy;
    printNumbersToLeaf_util(A->right, v, all);
    return;
}

int printNumbersToLeaf(TreeNode *A) {
    // Prints all paths from root to leaf
    vector<vector<int>> allSum;
    vector<int> curSum;
    int MOD = 1003;
    printNumbersToLeaf_util(A, curSum, allSum);

    int finalNum = 0;
    stringstream result;

    for (auto numV : allSum) {
        copy(numV.begin(), numV.end(), ostream_iterator<int>(result, ""));
        finalNum = (finalNum + stoi(result.str())) % MOD;
        result.str("");
    }

    return finalNum;
}

int sumNumbersToLeaf_util(TreeNode *A, int v) {
    //Sum numbers of tree from root to leaf helper
    if (!A)
        return 0;
    v = v * 10 + A->val;

    if (!(A->left) && !(A->right))
        return v % 1003;

    v %= 1003;
    return (sumNumbersToLeaf_util(A->left, v) + sumNumbersToLeaf_util(A->right, v)) % 1003;
}

int sumNumbers(TreeNode *A) {
    //Sum numbers of tree from root to leaf
    if (!A)
        return 0;
    return sumNumbersToLeaf_util(A, 0) % 1003;
}

int maxIndex(vector<int> &A, int strt, int end) {
    //Helper function to find index with max value in a range
    int i, max = A[strt], maxind = strt;
    for (i = strt + 1; i <= end; i++) {
        if (A[i] > max) {
            max = A[i];
            maxind = i;
        }
    }
    return maxind;
}

TreeNode *buildTreeHelper(int low, int high, vector<int> &A) {
    //Cartesian tree build helper. Given low and high and inorder, create tree
    if (low > high)
        return NULL;

    int maxmIndex = maxIndex(A, low, high);
    TreeNode *root = new TreeNode(A[maxmIndex]);
    root->left = buildTreeHelper(low, maxmIndex - 1, A);
    root->right = buildTreeHelper(maxmIndex + 1, high, A);

    return root;
}

TreeNode *buildTree(vector<int> &A) {
    //build a tree given an input vector that is the inorder traversal of that cartesian tree
    return buildTreeHelper(0, A.size() - 1, A);
}

bool nodeInTree(TreeNode *root, int item) {
    //Checks if a node with given value is in tree or not
    if (!root)
        return false;

    if (root->val == item)
        return true;
    else
        return nodeInTree(root->left, item) || nodeInTree(root->right, item);
}

void getPath(TreeNode *root, int a, char dir, vector<char> &path, vector<char> &final) {
    //Returns a path O, L , R from root (O) to node in a vector
    if (!root)
        return;

    if (root->val == a) {
        path.push_back(dir);
        final = path;
        return;
    }

    path.push_back(dir);
    getPath(root->left, a, 'L', path, final);
    if (!final.empty())
        return;

    getPath(root->right, a, 'R', path, final);
    path.pop_back();
}

TreeNode *LCA(TreeNode *root, int val1, int val2) {
    //Given two nodes which exist in tree, a recursive way to find LCA
    if (!root)
        return NULL;
    if (root->val == val1 || root->val == val2)
        return root;

    TreeNode *L = LCA(root->left, val1, val2);
    TreeNode *R = LCA(root->right, val1, val2);
    if (L && R)
        return root;   // If val1, val2 are on both sides
    return L ? L : R;  // either one of val1, val2 is on one side OR val1, val2 is not in L&R subtrees
}

int lca(TreeNode *A, int val1, int val2) {
    // Find lowest common ancestor of two nodes. No guarantee they belong to the tree
    TreeNode *p = A, *q = A;
    if (!nodeInTree(p, val1) || !(nodeInTree(q, val2)))
        return -1;

    vector<char> pathA, pathB;
    vector<char> finalA, finalB;
    vector<char> commonVal;

    getPath(p, val1, 'O', pathA, finalA);
    getPath(q, val2, 'O', pathB, finalB);

    for (int i = 0; i < min(finalA.size(), finalB.size()); i++) {
        if (finalA[i] == finalB[i])
            commonVal.push_back(finalA[i]);
        else
            break;
    }

    p = A;
    for (int i = 1; p && (i < commonVal.size()); i++) {
        if (commonVal[i] == 'L')
            p = p->left;
        else
            p = p->right;
    }
    return p->val;
}

TreeNode *invertTree(TreeNode *t) {
    //Given a binary tree, recursive way to invert it
    if (!t)
        return t;

    TreeNode *temp = t->right;
    t->right = t->left;
    t->left = temp;

    if (t->left)
        invertTree(t->left);
    if (t->right)
        invertTree(t->right);

    return t;
}

TreeNode *invertTreeIterative(TreeNode *t) {
    //Given a binary tree, iterative way to invert it
    if (!t)
        return t;

    queue<TreeNode *> q;
    q.push(t);

    while (!q.empty()) {
        TreeNode *p = q.front();
        q.pop();

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);

        TreeNode *temp = p->right;
        p->right = p->left;
        p->left = temp;
    }

    return t;
}

int kthsmallestUtil(TreeNode *t, int k) {
    // Given a bst, a function to find the kth smallest element in the tree utility
    if (!t)
        return -1;

    int kA = kthsmallestUtil(t->left, k);
    if (k == 0)
        return kA;
    k--;

    if (k == 0)
        return t->val;
    return kthsmallestUtil(t->right, k);
}

int kthsmallest(TreeNode *root, int k) {
    // Given a bst, a function to find the kth smallest element in the tree.
    return kthsmallestUtil(root, k);
}

TreeNode *flatten(TreeNode *t) {
    // Given a binary tree, flatten it to a linked list in-place.
    TreeNode *orig = t;
    if (!t)
        return t;

    if (t->left)
        flatten(t->left);
    if (t->right)
        flatten(t->right);

    TreeNode *temp = t->right;
    t->right = t->left;
    t->left = NULL;
    while (t->right)
        t = t->right;

    t->right = temp;
    return orig;
}

int t2Sum(TreeNode *t, int B) {
    // Given a bst and K, you have to find whether or not there exist nodes A and B such that A+ B = K.
    vector<int> A = inorderTraversal(t);

    map<int, int> M;
    for (int i = 0; i < A.size(); i++) {
        if (M.find(B - A[i]) != M.end())
            return 1;
        M[A[i]] = 1;
    }

    return 0;
}

int findIndex(vector<int> &in, int l, int h, int value) {
    for (int i = l; i <= h; ++i)
        if (in[i] == value)
            return i;
    return 0;
}

TreeNode *buildTreeInPreUtil(int preInd, vector<int> &preorder, vector<int> &inorder, int l, int h) {
    if (l >= h)
        return NULL;

    TreeNode *s = new TreeNode(preorder[preInd]);

    if (l == h)
        return s;

    int inIndex = findIndex(inorder, l, h, s->val);

    s->left = buildTreeInPreUtil(preInd + 1, preorder, inorder, l, inIndex - 1);
    s->right = buildTreeInPreUtil(preInd + inIndex - l + 1, preorder, inorder, inIndex + 1, h);

    return s;
}

TreeNode *buildTreeInPre(vector<int> &preorder, vector<int> &inorder) {
    //Given preorder and inorder traversal of a tree, construct the binary tree.
    if (inorder.size() == 0 || preorder.size() == 0)
        return NULL;
    return buildTreeInPreUtil(0, preorder, inorder, 0, inorder.size() - 1);
}

TreeNode *buildTreeInPostUtil(int postStart, int postEnd, vector<int> &postorder, vector<int> &inorder, int l, int h) {
    if (l > h)
        return NULL;

    TreeNode *s = new TreeNode(postorder[postEnd]);

    if (l == h)
        return s;

    int inIndex = findIndex(inorder, l, h, s->val);
    int length = inIndex - l;

    s->left = buildTreeInPostUtil(postStart, postStart + length - 1, postorder, inorder, l, inIndex - 1);
    s->right = buildTreeInPostUtil(postStart + length, postEnd - 1, postorder, inorder, inIndex + 1, h);

    return s;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    //Given inorder and postorder traversal of a tree, construct the binary tree.
    if (inorder.size() == 0 | postorder.size() == 0)
        return NULL;
    return buildTreeInPostUtil(0, postorder.size() - 1, postorder, inorder, 0, inorder.size() - 1);
}

vector<vector<int>> zigzagLevelOrder(TreeNode *A) {
    //Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).
    vector<vector<int>> ans;
    stack<TreeNode *> curLevel, nextLevel;
    bool leftToRight = true;

    if (!A)
        return ans;

    curLevel.push(A);
    vector<int> interim;

    while (!curLevel.empty()) {
        TreeNode *t = curLevel.top();
        curLevel.pop();
        interim.push_back(t->val);
        if (leftToRight) {
            if (t->left) nextLevel.push(t->left);
            if (t->right) nextLevel.push(t->right);
        } else {
            if (t->right) nextLevel.push(t->right);
            if (t->left) nextLevel.push(t->left);
        }

        if (curLevel.empty()) {
            ans.push_back(interim);
            interim.clear();
            leftToRight = !leftToRight;
            swap(curLevel, nextLevel);
        }
    }
    return ans;
}

vector<int> recoverTree(TreeNode *A) {
    //Two elements of a binary search tree (BST) are swapped by mistake. Tell us the 2 values swapping which the tree will be restored.
    vector<int> in = inorderTraversal(A);
    vector<int> anomally;

    int n = in.size();
    for (int i = n - 1; i > 0; i--) {
        if (in[i] < in[i - 1]) {
            int j = i - 1;
            while (j >= 0 && in[i] < in[j])
                j--;

            anomally.push_back(in[i]);
            anomally.push_back(in[++j]);
            break;
        }
    }
    sort(anomally.begin(), anomally.end());
    return anomally;
}

void printEdgeNodesUtil(TreeNode *root, int dist) {
    // Utility method to print a tree's edges/boundary
    if (!root)
        return;
    if (dist != 0)
        cout << root->val << " ";
    printEdgeNodesUtil(root->left, dist + 1);
    printEdgeNodesUtil(root->right, dist - 1);
}

void printEdgeNodes(TreeNode *root) {
    // Prints edge nodes of a tree
    if (!root)
        return;
    cout << root->val << " ";
    printEdgeNodesUtil(root, 0);
}

int main() {
    TreeNode *t = new TreeNode(20);
    t->right = new TreeNode(22);
    t->right->right = new TreeNode(25);

    t->left = new TreeNode(8);
    t->left->left = new TreeNode(4);
    t->left->right = new TreeNode(12);
    t->left->right->left = new TreeNode(10);
    t->left->right->right = new TreeNode(14);

    printEdgeNodes(t);

    return 0;
}
