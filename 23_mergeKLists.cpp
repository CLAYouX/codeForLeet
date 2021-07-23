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

ListNode* mergeKLists(vector<ListNode*>& lists);

ListNode *mergeTwoList(ListNode *l1, ListNode *l2) {

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

    tmp->next = l1 == nullptr? l2 : l1;

    ListNode *ans = dummyHead->next;
    delete dummyHead;

    return ans;
}

ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {

    if (left == right)
        return lists[left];

    int mid = left + (right-left)/2;
    ListNode *mergeL = mergeKLists(lists, left, mid);
    ListNode *mergeR = mergeKLists(lists, mid+1, right);

    ListNode *mergeLR = mergeTwoList(mergeL, mergeR);

    return mergeLR;
}

int main() {

    vector<ListNode*> lists;

    lists.push_back(new ListNode(1));
    ListNode *tmp = lists[0];
    tmp->next = new ListNode(4);
    tmp = tmp->next;
    tmp->next = new ListNode(5);

    lists.push_back(new ListNode(1));
    tmp = lists[1];
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(4);

    lists.push_back(new ListNode(2));
    tmp = lists[2];
    tmp->next = new ListNode(6);

    ListNode *ans = mergeKLists(lists);

    while(ans) {
        cout << ans->val << " ";
        ans= ans->next;
    }

    return 0;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {

    int n = lists.size();

    return mergeKLists(lists, 0, n-1);
}