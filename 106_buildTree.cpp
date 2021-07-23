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

int postIdx;
unordered_map<int, int> mp;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

TreeNode* build(vector<int> &inorder, vector<int> &postorder, int left, int right) {
    if (left > right)
        return nullptr;

    TreeNode *root = new TreeNode(postorder[postIdx]);

    int rootIndex = mp[postorder[postIdx]];

    --postIdx;
    root->right = build(inorder, postorder, rootIndex+1, right);
    root->left = build(inorder, postorder, left, rootIndex-1);

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

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode *root = buildTree(inorder, postorder);

    vector<vector<int>> ans = levelOrder(root);
    for (auto &v : ans) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    int n = inorder.size();
    if (n == 0)
        return nullptr;

    postIdx = n-1;
    int id = 0;
    for (int i = 0; i < n; ++i)
        mp[inorder[i]] = id++; 

    return build(inorder, postorder, 0, n-1);
}