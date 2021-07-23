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

ListNode* partition(ListNode* head, int x);

int main() {

    ListNode *head = new ListNode(1);
    ListNode *tmp = head;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(2);
    tmp = tmp->next;
    tmp->next = new ListNode(5);
    tmp = tmp->next;
    tmp->next = new ListNode(2);
    // tmp = tmp->next;
    // tmp->next = new ListNode(5);

    int x = 3;
    ListNode *ans = partition(head, x);

    while(ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}

ListNode* partition(ListNode* head, int x) {

    if (head == nullptr)
        return nullptr;

    ListNode *dummyHead1 = new ListNode(0), *dummyHead2 = new ListNode(0);
    ListNode *left = dummyHead1, *right = dummyHead2;

    ListNode *prev = head;
    while(prev) {
        if (prev->val < x) {
            left->next = prev;
            left = left->next;
        }else {
            right->next = prev;
            right = right->next;
        }

        prev = prev->next;
    }

    left->next = dummyHead2->next;
    right->next = nullptr;

    ListNode *ans = dummyHead1->next;
    delete dummyHead1, dummyHead2;

    return ans;
}