#include <bits/stdc++.h>
using namespace std;

 typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 }ListNode;

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode * p = A, * q = B;

    ListNode * head = new ListNode(0);
    ListNode * ans = head;

    while (p && q){
        if (p -> val < q -> val){
            ans -> next = new ListNode(p -> val);
            ans = ans -> next;
            p = p -> next;
        }
        else{
            ans -> next = new ListNode(q -> val);
            ans = ans -> next;
            q = q -> next;
        }
    }

    if (p)
        ans -> next = p;

    else
        ans -> next = q;

    ans -> next = NULL;
    return head -> next;
}


ListNode* removeNthFromEnd(ListNode* A, int B) {
    ListNode * a = A;
    int length = 0;
    while (a -> next){
        length += 1;
        a = a-> next;
    }

    if (B >= length)
        return A -> next;

    ListNode *q = A, *p = A, * prev = NULL;
    while (B --){
        if (!q)
            return A -> next;
        q = q -> next;
    }

    while (q){
        prev = p;
        p = p -> next;
        q = q -> next;
    }

    prev -> next = p -> next;
    delete p;
    return A;
}

ListNode * rotateRight(ListNode* A, int B) {
    ListNode *p = A, *q = A;
    int count = 1, sub = 0;

    while (p -> next){
        p = p -> next;
        count += 1;
    }
    B = B % count;
    if (B == 0)
        return A;

    while (sub ++ < count - B - 1)
        q = q -> next;

    q = q -> next;
    ListNode * firstLisEnd = q;

    ListNode * ans = q , * r = ans;
    while (q -> next){
        q = q -> next;
        r -> next = q;
        r = r -> next;
    }

    p = A;
    while (p != firstLisEnd){
        r -> next = p;
        r = r -> next;
        p = p -> next;
    }
    r -> next = NULL;

    return ans;
}

ListNode* reverseBetween(ListNode* A, int m, int n) {
    ListNode* newHead = new ListNode(-1);
    newHead -> next = A;
    ListNode* prev = newHead;
    for(auto i = 0 ; i < m-1 ; i++){
        prev = prev->next;
    }
    ListNode* reversedPrev = prev;
    prev = prev->next;
    ListNode* cur = prev->next;

    for(auto i = m ; i < n ; i++){
        prev->next = cur->next;
        cur->next = reversedPrev->next;
        reversedPrev->next = cur;
        cur = prev->next;
    }
    return newHead->next;
}

ListNode* reorderList(ListNode* A){
    vector<int> a, b;
    ListNode * p = A;
    while (p){
        a.push_back(p -> val);
        p = p -> next;
    }

    for(int i = 0 ; i <= (a.size() / 2) ; i ++){
        cout << "i : "<< i << endl;
        b.push_back(a[i]);
        if (i != a.size() - i - 1)
            b.push_back(a[a.size() - i - 1]);
    }

    p = A;
    for (int i = 0; i < b.size(); i++){
        p -> val = b[i];
        p = p -> next;
    }
    return A;
}

void display(ListNode * a){
    ListNode *p = a;
    while (p){
        cout << " " << p -> val <<" -> ";
        p = p -> next;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Adds two lists normally
    if(!l1)
        return l2;
    if(!l2)
        return l1;

    int carry = (l1->val + l2->val) / 10;
    ListNode *l3 = new ListNode((l1->val + l2->val) % 10);
    ListNode *tail = l3;
    l1 = l1->next;
    l2 = l2->next;

    while(l1 || l2 || carry)
    {
        int sum = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry);
        ListNode *t  = new ListNode(sum % 10);
        carry = sum / 10;

        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
        tail->next = t;
        tail = t;
    }

    return l3;
}


ListNode* partition(ListNode* A, int B){
    if (! A || ! (A -> next))
        return A;

    ListNode * lE = new ListNode(0);
    ListNode * gT = new ListNode(0);

    ListNode * p = lE, *q = gT, *r = A;
    ListNode * tail = NULL;

    while (r ){
        tail = r -> next;

        if (r -> val < B){
            p -> next = r;
            r -> next = NULL;
            p = p -> next;
        }
        else{
            q -> next = r;
            r -> next = NULL;
            q = q -> next;
        }
        r = tail;
    }
    q -> next = NULL;
    p -> next = gT -> next;
    return lE -> next;
}

ListNode* insertionSortList(ListNode* A) {
    if (!A || !(A -> next))
        return A;

    ListNode * pStart = A, * pEnd = A, *q = A -> next, *tail;
    while (q){
        tail = q -> next;

    }

}

int main(int argc, char *argv[]){
    ListNode * a = new ListNode(1);
    a -> next = new ListNode(4);
    a -> next -> next = new ListNode(3);
    a -> next -> next -> next = new ListNode(2);
    a -> next -> next -> next -> next = new ListNode(5);
    a -> next -> next -> next -> next -> next = new ListNode(2);


    ListNode * c = partition(a, atoi(argv[1]));
    ListNode * x = c;
    while (x){
        cout <<" "<<x -> val <<" -> ";
        x = x -> next;
    }
    return 0;
}


















//
