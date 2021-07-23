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

ListNode* deleteDuplicates(ListNode* head);

int main() {

    ListNode *head = new ListNode(1);
    ListNode *tmp = head;
    tmp->next = new ListNode(2);
    tmp = tmp->next;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(5);
    
    
    ListNode *ans = deleteDuplicates(head);
    while(ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}

ListNode* deleteDuplicates(ListNode* head) {

    if (head == nullptr)
        return nullptr;

    ListNode *dummyHead = new ListNode(0, head);
    ListNode *curr = dummyHead, *prev = head;

    while(prev) {
        if (prev->next && prev->val == prev->next->val) {
            int val = prev->val;
            while(prev && prev->val == val)
                prev = prev->next;
        }else {
            curr->next = prev;
            curr = curr->next;
            prev = prev->next;
        }
    }

    curr->next = prev;

    ListNode *ans = dummyHead->next;
    delete dummyHead;
    return ans;
}