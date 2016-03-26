#include <bits/stdc++.h>
using namespace std;

 // * Definition for singly-linked list.
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

RandomListNode* copyRandomList(RandomListNode* A) {
    map<RandomListNode *, RandomListNode*> hash;
    RandomListNode *m = A, *n = A;

    while (m){
        hash[m] = new RandomListNode(m -> label);
        m = m -> next;
    }

    while (n){
        hash[n] -> next = hash[n -> next];
        hash[n] -> random = hash[n -> random];
        n = n -> next;
    }

    return hash[A];
}


int main(){
    RandomListNode * first = new RandomListNode(1);
    RandomListNode * second = new RandomListNode(2);
    RandomListNode * third = new RandomListNode(3);
    first -> next = second;
    second -> next = third;

    first -> random = third;
    second -> random = first;
    third -> random = first;
}
