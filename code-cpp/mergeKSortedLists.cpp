#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

typedef pair<ListNode*, int> pii;

struct comparator {
    bool operator()(pii const& p1, pii const& p2) {
        // compare the first items in the pair
        return p1.first->val > p2.first->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) {
        return nullptr;
    }
    vector<ListNode*> rootPtrs;
    std::priority_queue<pii, vector<pii>, comparator> pq;
    int index = 0;
    for (auto rootNode : lists) {
        if (rootNode) {
            ListNode* rootCpy = rootNode;
            rootPtrs.push_back(rootCpy);
            std::cout << "Main Pushing " << rootCpy->val << " at index: " << index << endl;
            pq.push(make_pair(rootNode, index));
            index += 1;
        }
    }
    ListNode* sortHead = nullptr;
    ListNode* head = nullptr;

    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();

        if (sortHead == nullptr) {
            sortHead = top.first;
            head = sortHead;
        } else {
            sortHead->next = top.first;
            sortHead = sortHead->next;
        }
        index = top.second;
        //advance ptr of rootptr
        if (rootPtrs[index] != nullptr) {
            rootPtrs[index] = rootPtrs[index]->next;
            //offer this to the heap
            if (rootPtrs[index] != nullptr) {
                std::cout << "Pushing " << rootPtrs[index]->val << " at index: " << index << endl;
                pq.push(make_pair(rootPtrs[index], index));
            }
        }
    }
    //somelist is definitely missing at the end
    return head;
}

int main() {
    ListNode* rootA = new ListNode(1);
    rootA->next = new ListNode(4);
    rootA->next->next = new ListNode(5);

    ListNode* rootB = new ListNode(1);
    rootB->next = new ListNode(3);
    rootB->next->next = new ListNode(4);

    ListNode* rootC = new ListNode(2);
    rootB->next = new ListNode(6);

    vector<ListNode*> nodes = {rootA, rootB, rootC};
    ListNode* sorted = mergeKLists(nodes);
    while (sorted != NULL) {
        std::cout << sorted->val << " -> ";
        sorted = sorted->next;
    }
}