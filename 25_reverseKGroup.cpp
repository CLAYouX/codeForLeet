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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k);

pair<ListNode*, ListNode*> reverse(ListNode *head, ListNode *tail) {
    ListNode *prev = tail->next;
    ListNode *p = head;
    while(prev != tail) {
        ListNode *tmp = p->next;
        p->next = prev;
        prev = p;
        p = tmp;
    }

    return {tail, head};
}

int main() {

    ListNode *head = new ListNode(1);
    ListNode *tmp = head;
    tmp->next = new ListNode(2);
    tmp = tmp->next;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(5);

    int k = 2;

    ListNode *ans = reverseKGroup(head, k);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    
    return 0;
}

ListNode* reverseKGroup(ListNode* head, int k) {

    ListNode *dummyHead = new ListNode(0, head);
    ListNode *curr = dummyHead, *prev = head;

    while(prev) {

        ListNode *tail = curr;
        for (int i = 0; i < k ; ++i) {
            tail = tail->next;
            if (tail == nullptr)
                return dummyHead->next;
        }
            
        ListNode *next = tail->next;

        pair<ListNode*, ListNode*> newHeadTail = reverse(prev, tail);
        prev = newHeadTail.first;
        tail = newHeadTail.second;

        curr->next = prev;
        tail->next = next;
        curr = tail;
        prev = tail->next;
    }

    return dummyHead->next;
}