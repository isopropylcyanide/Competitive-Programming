#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 int height(TreeNode *A){
     if(!A)
     return 0;
     if(!(A -> left) && !(A -> right))
     return 1;
     int lh = 1 + height(A->left);
     int rh = 1 + height(A->right);
     if(lh < 0 || rh < 0)
     return INT_MIN;
     if(abs(lh - rh ) > 1)
     return INT_MIN;
     return max(lh, rh);

 }

 int isBalanced(TreeNode* A) {
     if(height(A)<0)
     return 0;
     return 1;

 }

vector<int> inorderTraversal(TreeNode* A) {
    vector<int> ans;

    if (!A)
        return ans;

    stack<TreeNode *> s;
    TreeNode *p = A;

    while (p){
        s.push(p);
        p = p-> left;
    }

    while (!s.empty()){
        p = s.top();
        ans.push_back(p -> val);
        s.pop();
        if (p -> right){
            p = p -> right;
            while (p){
                s.push(p);
                p = p-> left;
            }
        }
    }
    return ans;
}

vector<int> postorderTraversal(TreeNode* A){
    vector<int> ans;
    if (!A)
        return ans;

    stack<TreeNode *> s;
    s.push(A);

    while (!s.empty()){
        TreeNode * temp = s.top();
        if ( !(temp -> right) && !(temp -> left)){
            ans.push_back(temp -> val);
            s.pop();
        }
        else{
            if (temp -> right){
                s.push(temp -> right);
                temp -> right = NULL;
            }
            if (temp -> left){
                s.push(temp -> left);
                temp -> left = NULL;
            }
        }
    }
    return ans;
}

vector<int> preorderTraversal(TreeNode* A){
    vector<int> ans;
    if (!A)
        return ans;

    stack<TreeNode *> s;
    s.push(A);

    while (!s.empty()){
        TreeNode * temp = s.top();
        s.pop();
        ans.push_back(temp -> val);
        if (temp -> right)
            s.push(temp -> right);
        if (temp -> left)
            s.push(temp -> left);
    }
    return ans;
}

void inorder(TreeNode *p, vector<int> &V){
    if (p){
        inorder(p -> left, V);
        if (p)
            V.push_back(p -> val);
        inorder(p -> right, V);
    }
}

TreeNode* searchAndRef(TreeNode *A, int V){
        if (A -> val == V)
            return A;
        else if (A -> val < V)
            return searchAndRef(A -> right, V);
        else
            return searchAndRef(A -> left, V);
}

TreeNode * findMin(TreeNode *t){
    if (!t)
        return NULL;
    while (t -> left)
        t = t -> left;
    return t;
}

TreeNode* getSuccessor(TreeNode* A, int B){
    TreeNode *cur = searchAndRef(A, B);
    if (!cur)
        return NULL;

    //there's a right subtree
    if (cur -> right)
        return findMin(cur -> right);

    //there's no right. Find least ancestor for which cur is in leftsubtree
    TreeNode *succ = NULL, *anc = A;
    while (anc != cur){
        if (cur -> val < anc -> val){
            succ = anc;
            anc = anc -> left;
        }
        else
            anc = anc -> right;
    }
    return succ;
}

int isValidBST(TreeNode *A){
    vector<int> order = inorderTraversal(A);
    for (int i = 0; i < order.size() -1; i++)
        if (order[i] > order[i +1])
            return 0;
    return 1;
}

int isSameTree(TreeNode* A, TreeNode* B){
    if (!A && !B)
        return 1;
    else if ((A && !B) || (B && !A))
        return 0;
    else
        return A -> val == B -> val && isSameTree(A -> left, B -> left) && isSameTree(A -> right, B -> right);
}

void hasPathSumUtil(TreeNode *A, int curSum, vector<vector<int> > &all, vector<int> &cur){
    if (!A)
        return;

    int remSum = curSum - A -> val;
    cur.push_back(A -> val);

    if (!(A -> left) && !(A -> right)){
        if (remSum == 0)
            all.push_back(cur);
        cur.pop_back();
        return;
    }

    hasPathSumUtil(A -> left, curSum - A -> val, all, cur); hasPathSumUtil(A -> right, curSum - A -> val, all, cur);
    cur.pop_back();
    return;
}

vector<vector<int>> pathSum(TreeNode* A, int B){
    vector<vector<int> > allPaths;
    vector<int> curr;
    if (!A)
        return allPaths;
    hasPathSumUtil(A, B, allPaths, curr);
    return allPaths;
}

TreeNode * sortedArBSTUtil(const vector<int>&A, int l, int h){
    if (l > h)
        return NULL;
    int mid = (h + l)/2;
    TreeNode * root = new TreeNode(A[mid]);
    root -> left = sortedArBSTUtil(A, l, mid -1);
    root -> right = sortedArBSTUtil(A, mid + 1, h);

    return root;
}

TreeNode* sortedArrayToBST(const vector<int> &A) {
    return sortedArBSTUtil(A, 0, A.size() -1);
}

int isLeaf(TreeNode * t){
    return !(t -> left) && !(t -> right);
}

int isMirror(TreeNode *a, TreeNode *b){
    if (!a && !b)
        return 1;
    if (a && b && a -> val == b -> val &&
        isMirror(a -> left, b -> right) && isMirror(a -> right, b -> left))
        return 1;
    return 0;
}

int isSymmetric(TreeNode* A) {
    if (isMirror(A, A))
        return 1;
    return 0;
}


int maxDepth(TreeNode* A) {
    if (!A)
        return 0;
    else if (!(A -> left) && !(A -> right))
        return 1;
    else
        return max(maxDepth(A -> left), maxDepth(A -> right)) + 1;

}

int minDepth(TreeNode* A) {
    if (!A)
        return INT_MAX;
    else if (!(A -> left) && !(A -> right))
        return 1;
    else
        return min(minDepth(A -> left), minDepth(A -> right)) + 1;
}


void printNumbersToLeaf_util(TreeNode *A, vector<int> &v, vector<vector<int>> &all){
    if (!A)
        return;

    if (!(A -> left) && !(A -> right)){
        v.push_back(A -> val);
        all.push_back(v);
    }

    v.push_back(A -> val);
    vector<int> copy(v);
    printNumbersToLeaf_util(A -> left, v, all);
    v = copy;
    printNumbersToLeaf_util(A -> right, v, all);
    return ;
}

int printNumbersToLeaf(TreeNode* A) {
    vector< vector<int>>  allSum;
    vector<int> curSum;
    int MOD = 1003;
    printNumbersToLeaf_util(A, curSum, allSum);

    int finalNum = 0;
    stringstream result;

    for (auto numV: allSum){
        copy(numV.begin(), numV.end(), ostream_iterator<int>(result,""));
        finalNum = (finalNum + stoi(result.str()) ) % MOD;
        result.str("");
    }

    return finalNum;
}

int sumNumbersToLeaf_util(TreeNode *A, int v){
    if (!A)
        return 0;
    v = v * 10 +  A -> val;

    if (!(A -> left) && !(A -> right))
        return v % 1003;

    v %= 1003;
    return (sumNumbersToLeaf_util(A -> left, v) + sumNumbersToLeaf_util(A -> right, v)) % 1003;
}


int sumNumbers(TreeNode* A) {
    if (!A)
        return 0;
    return sumNumbersToLeaf_util(A, 0) % 1003;
}

int maxIndex(vector<int> &A, int strt, int end){
    int i, max = A[strt], maxind = strt;
    for(i = strt+1; i <= end; i++){
        if(A[i] > max){
            max = A[i];
            maxind = i;
        }
    }
    return maxind;
}

TreeNode *buildTreeHelper(int low, int high, vector<int> &A){
    if (low > high)
        return NULL;

    int maxmIndex = maxIndex(A, low, high);
    TreeNode * root = new TreeNode(A[maxmIndex]);
    root -> left = buildTreeHelper(low, maxmIndex -1, A);
    root -> right = buildTreeHelper(maxmIndex +1, high, A);

    return root;
}

TreeNode* buildTree(vector<int> &A) {
    //build a tree given an input vector that is the inorder traversal of that cartesian tree
    return buildTreeHelper(0, A.size() -1, A);
}


int main(){
    TreeNode *t = new TreeNode(1);
    t -> right = new TreeNode(2);
    t -> right -> left = new TreeNode(4);
    t -> right -> right = new TreeNode(3);

    t -> left = new TreeNode(2);
    t -> left -> left = new TreeNode(3);
    t -> left -> right = new TreeNode(4);

    vector<int> A = {5, 10, 40, 30, 28};
    for (auto a : inorderTraversal(buildTree(A)))
        cout << a << " ";
    return 0;
}
