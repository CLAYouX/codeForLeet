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

vector<vector<int>> pathSum(TreeNode* root, int targetSum);

void dfs(vector<vector<int>> &ans, vector<int> &path, TreeNode *root, int targetSum) {
    if (root == nullptr)
        return;

    if (abs(targetSum) < abs(root->val))
        return;

    path.push_back(root->val);
    targetSum -= root->val;
    if (root->left == 0 && root->right == 0 && targetSum == 0)
        ans.push_back(path);
    dfs(ans, path, root->left, targetSum);
    dfs(ans, path, root->right, targetSum);
    targetSum += root->val;
    path.pop_back();
}

int main() {

    TreeNode *root = new TreeNode(-2);
    TreeNode *tmp = root;
    tmp->right = new TreeNode(-3);
    // tmp = tmp->left;
    // tmp->left = new TreeNode(11);
    // tmp = tmp->left;
    // tmp->left = new TreeNode(7);
    // tmp->right = new TreeNode(2);
    // tmp = root;
    // tmp->right = new TreeNode(8);
    // tmp = tmp->right;
    // tmp->left = new TreeNode(13);
    // tmp->right = new TreeNode(4);
    // tmp = tmp->right;
    // tmp->left = new TreeNode(5);
    // tmp->right = new TreeNode(1);

    vector<vector<int>> ans = pathSum(root, -5);

    for (auto &v : ans) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

    vector<vector<int>> ans;
    vector<int> path;

    if (root == nullptr)
        return ans;

    dfs(ans, path, root, targetSum);

    return ans;
}