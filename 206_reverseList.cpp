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

ListNode* reverseList(ListNode* head);

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

    ListNode *ans = reverseList(head);
    while(ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}

ListNode* reverseList(ListNode* head) {

    if (head == nullptr)
        return nullptr;

    ListNode *curr = head;
    ListNode *prev = nullptr;
    while(curr != nullptr) {
        ListNode *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }

    return prev;
}