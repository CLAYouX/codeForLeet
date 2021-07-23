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

vector<int> inorderTraversal(TreeNode* root);

int main() {

    TreeNode *root = new TreeNode(1);
    TreeNode *tmp = root;
    tmp->left = new TreeNode(2);
    // tmp = tmp->right;
    // tmp->left = new TreeNode(3);

    vector<int> ans = inorderTraversal(root);
    for (auto &i : ans)
        cout << i << " ";

    return 0;
}

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