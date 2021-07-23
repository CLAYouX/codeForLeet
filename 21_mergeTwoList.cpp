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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

int main() {

    // ListNode *l1 = new ListNode(1), *tmp1 = l1;
    // tmp1->next = new ListNode(2);
    // tmp1 = tmp1->next;
    // tmp1->next = new ListNode(4);

    // ListNode *l2 = new ListNode(1), *tmp2 = l2;
    // tmp2->next = new ListNode(3);
    // tmp2 = tmp2->next;
    // tmp2->next = new ListNode(4);

    ListNode *l1 = nullptr, *l2 = new ListNode(0);

    ListNode *ans = mergeTwoLists(l1, l2);
    while(ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode *dummyHead = new ListNode(0);
    ListNode *tmp = dummyHead;
    while(l1 && l2) {
        if (l1->val <= l2->val) {
            tmp->next = l1;
            l1 = l1->next;
        }else {
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }

    if (l1)
        tmp->next = l1;

    if (l2)
        tmp->next = l2;

    ListNode *ans = dummyHead->next;
    delete dummyHead;

    return ans;
}