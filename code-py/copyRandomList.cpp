#include <bits/stdc++.h>

/**
 * A linked list of length n is given such that each node contains an additional random
 *  pointer, which could point to any node in the list, or null.
*/
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node *curr = head, *tmp;
    //create an augmented list..carefully. Note that random ptrs are not touched
    while (curr != NULL) {
        Node* tmp = curr->next;
        curr->next = new Node(curr->val);
        curr->next->next = tmp;
        curr = tmp;
    }
    curr = head;
    while (curr != NULL) {
        if (curr->next) {
            curr->next->random = curr->random ? curr->random->next : curr->random;
        }
        curr = curr->next ? curr->next->next : curr->next;
    }
    //now both lists are cloned in place
    //segregate them
    Node* original = head;
    Node* copy = head->next;
    tmp = copy;

    while (original && copy) {
        original->next = original->next ? original->next->next : original->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        original = original -> next;
        copy = copy -> next;
    }
    return tmp;
}

int main() {
    Node* head = new Node(20);
    Node* copy = copyRandomList(head);
    return 0;
}