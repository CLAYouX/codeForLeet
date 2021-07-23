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

ListNode* removeNthFromEnd(ListNode* head, int n);

int main() {

    ListNode *root = new ListNode(1);
    ListNode *tmp = root;
    tmp->next = new ListNode(2);
    // tmp = tmp->next;
    // tmp->next = new ListNode(3);
    // tmp = tmp->next;
    // tmp->next = new ListNode(4);
    // tmp = tmp->next;
    // tmp->next = new ListNode(5);

    int n = 1;

    ListNode *ans = removeNthFromEnd(root, n);

    while(ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {

    if (head == nullptr)
        return nullptr;

    ListNode *dummyHead = new ListNode(0, head);
    ListNode *prev = dummyHead, *curr = dummyHead;

    for (int i = 0; i < n; ++i)
        prev = prev->next;

    while(prev->next != nullptr) {
        prev = prev->next;
        curr = curr->next;
    }

    curr->next = curr->next->next;

    ListNode *ans = dummyHead->next;
    delete dummyHead;

    return ans;
}