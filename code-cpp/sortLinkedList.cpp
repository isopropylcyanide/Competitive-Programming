#include <bits/stdc++.h>

/*
 * Given the head of a linked list, return the list after sorting it in ascending order.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeNodes(ListNode* left, ListNode* right) {
    // ListNode* mergeNodes(ListNode* list1, ListNode* list2) {
    //return head of the sorted items in the list post merge
    ListNode* temp = new ListNode(INT_MIN);
    ListNode* newHead = temp;

    //iterate by looking at the front of each
    while (left && right) {
        if (left->val < right->val) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    temp->next = left ? left : right;
    //now tmp is at the end while we had to return the head;
    return newHead->next;
}

ListNode* getMid(ListNode* head) {
    ListNode* slowPrev = NULL;
    ListNode* fast = head;
    while (fast && fast->next) {
        slowPrev = (slowPrev == NULL) ? fast : slowPrev->next;
        fast = fast->next->next;
    }
    ListNode* mid = slowPrev->next;
    slowPrev->next = NULL;
    return mid;
}
ListNode* sortList(ListNode* head) {
    //just an idea..two pointers one fast and other slow
    //at the end one is at the middle;
    if (!head || !head->next) {
        return head;
    }
    //finding middle element
    ListNode* temp = head;
    ListNode* mid = getMid(head);
    ListNode* left = sortList(temp);
    ListNode* right = sortList(mid);
    return mergeNodes(left, right);
}

ListNode* sortListWithSpace(ListNode* head) {
    priority_queue<int, vector<int>, std::greater<int>> elemsQueueMin;
    ListNode* ref = head;
    while (ref != NULL) {
        elemsQueueMin.push(ref->val);
        ref = ref->next;
    }
    ref = head;
    while (ref != NULL) {
        ref->val = elemsQueueMin.top();
        ref = ref->next;
        elemsQueueMin.pop();
    }
    return head;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ListNode* head = new ListNode(4);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    sortList(head);
    while (head != NULL) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << endl;

    return 0;
}
