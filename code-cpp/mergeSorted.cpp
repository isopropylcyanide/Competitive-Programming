#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 struct comparator{
     bool operator()(ListNode *a, ListNode *b){
         return a -> val > b -> val;
     }
 };

ListNode* mergeKLists(vector<ListNode*> &A) {
    //Starting list would contain the list with the minimum head
    ListNode *head = new ListNode(0);
    priority_queue<ListNode *, vector<ListNode *>, comparator> minHeap;

    for (auto p : A){
        if (p)
            minHeap.push(p);
    }

    ListNode *p = head;
    while (minHeap.size()){
        ListNode *temp = minHeap.top();
        minHeap.pop();

        p -> next = temp;
        if (temp -> next)
            minHeap.push(temp -> next);

        p = p-> next;
    }
    return head -> next;
}

int main(){
    ListNode *A = new ListNode(1);
    A -> next = new ListNode(10);
    A -> next -> next = new ListNode(20);

    ListNode *B = new ListNode(4);
    B -> next = new ListNode(11);
    B -> next -> next = new ListNode(13);

    ListNode *C = new ListNode(3);
    C -> next = new ListNode(8);
    C -> next -> next = new ListNode(9);

    vector<ListNode*> a{A, B, C};
    ListNode * res = mergeKLists(a);
    while (res != NULL){
        cout << " " << res -> val;
        res = res -> next;
    }
    return 0;
}
