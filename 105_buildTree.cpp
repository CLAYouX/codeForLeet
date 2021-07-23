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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

TreeNode* build(vector<int> &preorder, int b1, int e1, vector<int> &inorder, int b2, int e2) {

    if (b1 > e1)
        return nullptr;

    TreeNode *root = new TreeNode(preorder[b1]);
    int leftTreeNum = 0;
    for (int i = b2; i != e2; ++i) {
        if (inorder[i] == preorder[b1])
            break;

        ++leftTreeNum;
    }

    root->left = build(preorder, b1+1, b1+leftTreeNum, inorder, b2, b2+leftTreeNum-1);
    root->right = build(preorder, b1+leftTreeNum+1, e1, inorder, b2+leftTreeNum+1, e2);

    return root;
}

vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        ans.push_back(vector<int>());
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode *tmp = q.front();
            q.pop();
            ans.back().push_back(tmp->val);
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
    }

    return ans;
}

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = buildTree(preorder, inorder);

    vector<vector<int>> ans = levelOrder(root);
    for (auto &v : ans) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    int n = preorder.size();
    if (n == 0)
        return nullptr;

    return build(preorder, 0, n-1, inorder, 0, n-1);
}