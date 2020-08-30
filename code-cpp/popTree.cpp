#include <bits/stdc++.h>
using namespace std;

/*
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
*/

struct TreeLinkNode {
     int val;
     TreeLinkNode *left, *right, *next;
     TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode* A) {
    //Connect next pointers.
    // Idea: Do a level order traversal and set next to next node in the queue
    queue<TreeLinkNode*> q;
    vector< vector <TreeLinkNode *>> order;
    if (!A || (!(A -> left) && !(A -> right)))
        return;

    q.push(A);
    q.push(NULL);
    vector<TreeLinkNode *> interim;
    TreeLinkNode *cur = NULL;

    while (!q.empty()){
        cur = q.front();
        q.pop();

        if (cur == NULL){
            order.push_back(interim);
            interim.clear();
            if (!q.empty())
                q.push(NULL);
            continue;
        }
        interim.push_back(cur);
        if (cur -> left)
            q.push(cur -> left);
        if (cur -> right)
            q.push(cur -> right);
    }

    for (auto a : order){
        for (int i = 0; i < a.size(); i++){
            if ( i < a.size() - 1)
                a[i] -> next = a[i +1];
            else a[i] -> next = NULL;
        }
    }

}

int main(){
    TreeLinkNode * t = new TreeLinkNode(1);
    t -> left = new TreeLinkNode(2);
    t -> right = new TreeLinkNode(3);
    t -> left -> left = new TreeLinkNode(4);
    t -> left -> right = new TreeLinkNode(5);
    t -> right -> left = new TreeLinkNode(6);
    t -> right -> right = new TreeLinkNode(7);

    connect(t);

    return 0;
}
