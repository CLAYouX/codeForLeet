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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main() {

    ListNode *l1 = new ListNode(9), *l2 = new ListNode(9);
    ListNode *tmp1 = l1, *tmp2 = l2;

    tmp1->next = new ListNode(9);
    tmp1 = tmp1->next;
    tmp1->next = new ListNode(9);
    tmp1 = tmp1->next;
    tmp1->next = new ListNode(9);
    tmp1 = tmp1->next;
    tmp1->next = new ListNode(9);
    tmp1 = tmp1->next;
    tmp1->next = new ListNode(9);
    tmp1 = tmp1->next;
    tmp1->next = new ListNode(9);

    tmp2->next = new ListNode(9);
    tmp2 = tmp2->next;
    tmp2->next = new ListNode(9);
    tmp2 = tmp2->next;
    tmp2->next = new ListNode(9);

    ListNode *ans = addTwoNumbers(l1, l2);

    while(ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    if (l1 == nullptr && l2 == nullptr)
        return nullptr;

    ListNode *dummyHead = new ListNode(0);
    ListNode *curr = dummyHead;
    int carry = 0;
    while(l1 && l2) {
        int add = l1->val + l2->val + carry;
        curr->next = new ListNode(add%10);
        carry = add / 10;
        curr = curr->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    if (carry == 0)
        curr->next = (l1 == nullptr)? l2 : l1;
    else {
        if (l1 == nullptr) {
            while(l2) {
                int add = l2->val + carry;
                curr->next = new ListNode(add%10);
                carry = add / 10;
                curr = curr->next;
                l2 = l2->next;
            }
        }else {
            while(l1) {
                int add = l1->val + carry;
                curr->next = new ListNode(add%10);
                carry = add / 10;
                curr = curr->next;
                l1 = l1->next;
            }
        }
    }

    curr->next = (carry == 0) ? nullptr : new ListNode(carry);

    ListNode *ans = dummyHead->next;
    delete dummyHead;

    return ans;
}