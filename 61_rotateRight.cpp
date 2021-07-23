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

ListNode* rotateRight(ListNode* head, int k);

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
    
    ListNode *ans = rotateRight(head, 2);
    while(ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}

ListNode* rotateRight(ListNode* head, int k) {

    if (head == nullptr)
        return nullptr;

    int n = 0;
    ListNode *tmp = head;
    while (tmp != nullptr)
    {
        ++n;
        tmp = tmp->next;
    }

    k %= n;

    if (k == 0)
        return head;

    ListNode *dummyHead = new ListNode(0, head);
    ListNode *prev = dummyHead, *tail = dummyHead;
    while(k) {
        prev = prev->next;
        --k;
    }

    while(prev->next != nullptr) {
        prev = prev->next;
        tail = tail->next;
    }

    cout << prev->val << " " << tail->val << endl;

    prev->next = dummyHead->next;
    dummyHead->next = tail->next;
    tail->next = nullptr;

    ListNode *ans = dummyHead->next;
    delete dummyHead;
    return ans;
}