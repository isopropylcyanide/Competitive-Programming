#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode * lis;

 int count(ListNode *node){
     int size = 0;
     while (node) {
         ++size;
         node = node->next;
     }
     return size;
 }

 TreeNode *generate(int n){
     if (n == 0)
         return NULL;
     TreeNode *node = new TreeNode(0);
     node->left = generate(n / 2);
     node->val = lis->val;
     lis = lis->next;
     node->right = generate(n - n / 2 - 1);
     return node;
 }

 TreeNode *sortedListToBST(ListNode *head) {
     lis = head;
     return generate(count(head));
 }

 vector<int> inorderTraversal(TreeNode* A) {
     //Performs iterative inorder traversal
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

int main(){
    ListNode *A = new ListNode(1);
    A -> next = new ListNode(2);
    A -> next -> next = new ListNode(3);
    A -> next -> next -> next = new ListNode(4);
    A -> next -> next -> next -> next = new ListNode(41);

    TreeNode * t = sortedListToBST(A);
    for (auto a : inorderTraversal(t))
        cout << a << " -> ";
    cout << endl;
}
