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

TreeNode* sortedArrayToBST(vector<int>& nums);

TreeNode *build(vector<int> &nums, int left, int right) {

    if (left > right)
        return nullptr;

    int mid = left + (right-left)/2;

    TreeNode *root = new TreeNode(nums[mid]);

    root->left = build(nums, left, mid-1);
    root->right = build(nums, mid+1, right);

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

    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode *root = sortedArrayToBST(nums);

    vector<vector<int>> ans = levelOrder(root);
    for (auto &v : ans) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {

    int n = nums.size();
    if (n == 0)
        return nullptr;

    return build(nums, 0, n-1);
}