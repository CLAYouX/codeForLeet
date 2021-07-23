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

bool isValidBST(TreeNode* root);

int main() {

    TreeNode *root = new TreeNode(5);
    TreeNode *tmp = root;
    tmp->left = new TreeNode(1);
    tmp = root;
    tmp->right = new TreeNode(4);
    tmp = tmp->right;
    tmp->left = new TreeNode(3);
    tmp->right = new TreeNode(6);

    cout << isValidBST(root) << endl;

    return 0;
}

bool isValidBST(TreeNode* root) {

    if (root == nullptr)
        return true;

    stack<TreeNode*> stk;
    int maxVal = INT_MIN;
    while(!stk.empty() || root != nullptr) {
        while(root) {
            stk.push(root);
            root = root->left;
        }

        TreeNode *tmp = stk.top();
        stk.pop();
        if (tmp->val < maxVal)
            return false;

        maxVal = tmp->val;
        root = tmp->right;
    }

    return true;
}