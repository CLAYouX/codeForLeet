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

ListNode* reverseBetween(ListNode* head, int left, int right);

pair<ListNode*, ListNode*> reverse(ListNode *head, ListNode *tail) {

    ListNode *prev = nullptr;
    ListNode *curr = head;
    while(curr) {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return {tail, head};
}

int main() {

    ListNode *head = new ListNode(1);
    // ListNode *tmp = head;
    // tmp->next = new ListNode(2);
    // tmp = tmp->next;
    // tmp->next = new ListNode(3);
    // tmp = tmp->next;
    // tmp->next = new ListNode(4);
    // tmp = tmp->next;
    // tmp->next = new ListNode(5);
    // tmp = tmp->next;
    // tmp->next = new ListNode(2);

    ListNode *ans = reverseBetween(head, 1, 1);
    while(ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {

    if (head == nullptr)
        return nullptr;

    ListNode *dummyHead = new ListNode(0, head);
    ListNode *prev = dummyHead, *tail = dummyHead;
    for (int i = 0; i < right; ++i) {
        if (i < left-1)
            tail = tail->next;

        prev = prev->next;
    }

    ListNode *curr = tail, *next = prev->next;
    prev->next = nullptr;

    pair<ListNode*, ListNode*> p = reverse(tail->next, prev);
    curr->next = p.first;
    p.second->next = next;

    ListNode *ans = dummyHead->next;
    delete dummyHead;

    return ans;
}