#include <bits/stdc++.h>
using namespace std;

//Level order traversal

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

vector<vector<int> > levelOrder(TreeNode* A) {
    //Store level traversal in a vector
    vector<vector<int> > order;
    vector<int> curr;

    queue<TreeNode *> q;
    q.push(A);
    q.push(NULL);

    while (!q.empty()){
        TreeNode *t = q.front();
        q.pop();

        //if t is NULL..cout new line
        if (t == NULL){
            order.push_back(curr);
            curr.clear();
            if (!q.empty())
                q.push(NULL);
        }

        else{
            curr.push_back(t -> val);
            if (t -> left)
            q.push(t -> left);
            if (t -> right)
            q.push(t -> right);
        }
    }

    return order;
}

int main(){

    TreeNode *t = new TreeNode(3);
    t -> right = new TreeNode(20);
    t -> right -> right = new TreeNode(7);
    t -> right -> left = new TreeNode(15);

    t -> left = new TreeNode(9);
    t -> left -> left = new TreeNode(11);
    for (auto a : levelOrder(t)){
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }

    return 0;
}
