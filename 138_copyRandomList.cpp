#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<iterator>
#include<limits>
#include<algorithm>
#include<map>
#include<utility>
#include<set>
#include<unordered_map>
#include<stack>
#include<queue>
#include<unordered_set>
#include<numeric>
using namespace std;

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

Node* copyRandomList(Node* head);

int main() {


    return 0;
}

Node* copyRandomList(Node* head) {

    if (head == nullptr)
        return nullptr;

    Node *curr = head;
    while (curr) {
        Node *clone = new Node(curr->val);
        clone->next = curr->next;
        curr->next = clone;
        curr = clone->next;
    }

    curr = head;
    while (curr) {
        if (curr->random != nullptr)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    Node *cloneHead = head->next;
    Node *cloneCurr = cloneHead;
    curr = head;
    curr->next = cloneCurr->next;
    curr = curr->next;
    while(curr) {
        cloneCurr->next = curr->next;
        cloneCurr = cloneCurr->next;
        curr->next = cloneCurr->next;
        curr = curr->next;
    }

    return cloneHead;
}