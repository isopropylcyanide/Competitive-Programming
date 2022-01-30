#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

/*
 * You need to construct a binary tree from a string consisting of parenthesis and integers.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct partitionResult {
    bool matched;
    int start, end;

    partitionResult(bool matched, int start, int anEnd) : matched(matched), start(start), end(anEnd) {}
};

partitionResult getStringBetweenParenthesisIfExists(const string &s, int low, int high) {
    bool startedMatching = false, validMatch = false;
    int imbalance = 0;
    int left = low, right = high;
    while (low <= high) {
        if (s[low] == '(') {
            imbalance += 1;
            if (!startedMatching) {
                left = low;
                startedMatching = true;
            }
        } else if (s[low] == ')') {
            imbalance -= 1;
        }
        if (startedMatching && imbalance == 0) { // balanced
            right = low;
            validMatch = true;
            break;
        }
        low += 1;
    }
    return partitionResult(validMatch, left, right);
}

TreeNode *str2tree(string s, int l, int h) {
    // start with node and try to find partition of left and right nodes (if exist)
    int i = l + 1;
    const partitionResult &leftResult = getStringBetweenParenthesisIfExists(s, i, h);
    const partitionResult &rightResult = getStringBetweenParenthesisIfExists(s, leftResult.end + 1, h);

    // task is to interpret everything from s[l] until the end (governed by startLeft)
    int numberStart = l, numberEnd = h;
    if (leftResult.matched) {
        numberEnd = leftResult.start - 1;
    }
    bool positive = true;
    if (s[l] == '-') {
        positive = false;
        numberStart = numberStart + 1;
    }
    int rootNode = 0, power10 = 0;
    for (int idx = numberEnd; idx >= numberStart; idx--) {
        rootNode = (s[idx] - '0') * pow(10, power10) + rootNode;
        power10 += 1;
    }
    rootNode = positive ? rootNode : -rootNode;

    TreeNode *root = new TreeNode(rootNode);
    if (leftResult.matched) {
        root->left = str2tree(s, leftResult.start + 1, leftResult.end - 1);
    }
    if (rightResult.matched) {
        root->right = str2tree(s, rightResult.start + 1, rightResult.end - 1);
    }
    return root;
}

TreeNode *str2tree(string s) {
    if (s.empty()) {
        return NULL;
    }
    return str2tree(s, 0, s.size() - 1);
}

void levelOrd(TreeNode *A) {
    //levelOrd next pointers.
    queue<TreeNode *> q;
    if (!A || (!(A->left) && !(A->right)))
        return;

    q.push(A);
    q.push(NULL);  //insert null marker initially for the root
    TreeNode *cur = NULL;

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
    std::cout << "****\n";
}


int main() {
    levelOrd(str2tree("4(2(3)(1))(6(5))"));
    levelOrd(str2tree("4(2(3)(1))(6(5)(7))"));
    levelOrd(str2tree("-4(2(3)(1))(6(5)(7))"));
    levelOrd(str2tree("51(232)(434)"));
    levelOrd(str2tree("4"));

    return 0;
}
