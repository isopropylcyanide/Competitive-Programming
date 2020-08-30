#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    Node * next, *prev;
    Node(){}
}Node;

void display(Node *head, bool both = true){
    // Display the list using both next and prev pointers
    Node *p = head;
    cout << endl;
    while (p ){
        cout << p -> data << " -> ";
        p = p -> next;
    }
    cout << endl;
    if (both){
        p = head;
        while (p -> next)
        p = p -> next;
        while (p){
            cout << p -> data << " <- ";
            p = p -> prev;
        }
        cout << endl;
    }
}

Node * createNode(int data){
    Node *x = new Node();
    x -> next = NULL;
    x -> prev = NULL;
    x -> data = data;
    return x;
}

Node * insert(Node *head, int data){
    // Inserts a Node at the end of the list
    Node *p = head;
    while(p -> next)
        p = p -> next;
    p -> next = createNode(data);
    p -> next -> prev = p;
    return head;
}

Node* SortedInsert(Node *head,int data){
    Node * p = head;
    Node * temp = createNode(data);
    if (!p)
        return temp;

    else if (p -> data > data){
        // insert at begining
        temp -> next = p;
        p -> prev = temp;
        head = temp;
    }
    else{
        while (p -> next && p -> next -> data < data)
            p = p -> next;
        // Insert at the middle
        Node * t = p -> next;
        p -> next = temp;
        temp -> prev = p;
        if (t){
            temp -> next = t;
            t -> prev = temp;
        }
    }
    return head;
}

Node * revDLLUtil(Node *p, Node *q){
    // Util method to recur reverse a DLL
    Node * t = p -> next;
    p -> next = q;
    if (q)
        q -> prev = p;
    if (!t)
        return p;
    return revDLLUtil(t, p);
}

Node * reverseDLLrecur(Node *head){
    // Reverse a DLL recursively
    if (!head)
        return head;
    head = revDLLUtil(head, NULL);
    head -> prev = NULL;
    return head;
}

Node * reverseIter(Node * head){
    // iteratively reverse a doubly linked list
    Node * q = NULL, *p = head;
    while(p){
        q = p -> prev;
        p -> prev = p -> next;
        p -> next = q;
        p = p -> prev;
    }
    if (q)
        head = q -> prev;
    return head;
}
int main(){
    // Create a linked list, add some values and reverse it both recursively and iteratively

    Node *head = NULL;
    head = SortedInsert(head, 4);
    head = SortedInsert(head, 2);
    head = SortedInsert(head, 6);
    head = SortedInsert(head, 1);
    head = SortedInsert(head, 4);
    head = SortedInsert(head, 2);
    head = SortedInsert(head, 3);
    head = SortedInsert(head, 7);
    head = SortedInsert(head, 9);
    head = SortedInsert(head, 10);
    display(head);

    cout << "\n Now reversing: \n";
    head = reverseIter(head);
    display(head);
    return 0;
}
