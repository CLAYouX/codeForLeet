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
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head);

int main() {

    ListNode *head = new ListNode(3);
    ListNode *tmp = head;
    tmp->next = new ListNode(2);
    tmp = tmp->next;
    ListNode *cycle = tmp;
    tmp->next = new ListNode(0);
    tmp = tmp->next;
    tmp->next = new ListNode(-4);
    tmp = tmp->next;
    tmp->next = cycle;

    ListNode *ans = detectCycle(head);
    cout << ans->val << endl;

    return 0;
}

ListNode *detectCycle(ListNode *head) {

    ListNode *slow = head, *fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;

        if (slow == fast)
            break;
    }

    if (fast == nullptr || fast->next == nullptr)
        return nullptr;

    ListNode *cycleIn = head;
    while(cycleIn != fast) {
        cycleIn = cycleIn->next;
        fast = fast->next;
    }

    return cycleIn;
}