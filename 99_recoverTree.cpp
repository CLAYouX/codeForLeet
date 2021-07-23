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

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recoverTree(TreeNode* root);

vector<int> inorderTraversal(TreeNode* root) {

    if (root == nullptr)
        return {};

    vector<int> ans;
    stack<TreeNode*> stk;
    while(!stk.empty() || root != nullptr) {
        while(root) {
            stk.push(root);
            root = root->left;
        }

        TreeNode *tmp = stk.top();
        stk.pop();
        ans.push_back(tmp->val);
        root = tmp->right;
    }

    return ans;
}

int main() {

    TreeNode *root = new TreeNode(3);
    TreeNode *tmp = root;
    tmp->left = new TreeNode(1);
    tmp = root;
    tmp->right = new TreeNode(4);
    tmp = tmp->right;
    tmp->left = new TreeNode(2);

    recoverTree(root);
    vector<int> ans = inorderTraversal(root);
    for (auto &i : ans)
        cout << i << " ";

    return 0;
}

void recoverTree(TreeNode* root) {

    if (root == nullptr)
        return;

    
    TreeNode *swap1 = nullptr, *swap2 = nullptr;
    stack<TreeNode*> stk;
    long long lastVal = (long long)INT_MIN - 1;
    bool flag = false;
    while(!stk.empty() || root != nullptr) {
        while(root) {
            stk.push(root);
            root = root->left;
        }

        TreeNode *tmp = stk.top();
        stk.pop();

        if (tmp->val < lastVal) {
            swap2 = tmp;
            flag = true;
        }

        lastVal = tmp->val;
        root = tmp->right;
        if (!flag)
            swap1 = tmp;
    }

    swap(swap1->val, swap2->val);
}