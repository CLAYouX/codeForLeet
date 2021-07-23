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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedListToBST(ListNode* head);

ListNode* getMedian(ListNode *left, ListNode *right) {

    ListNode *slow = left, *fast = left;
    while(fast != right && fast->next != right) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

TreeNode* build(ListNode*left, ListNode*right) {
    if(left == right)
        return nullptr;

    ListNode *mid = getMedian(left, right);
    TreeNode *root = new TreeNode(mid->val);

    root->left = build(left, mid);
    root->right = build(mid->next, right);

    return root;
}

int main() {


    return 0;
}

TreeNode* sortedListToBST(ListNode* head) {

    if (head == nullptr)
        return nullptr;

    return build(head, nullptr);
}