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

bool hasPathSum(TreeNode* root, int targetSum);

int main() {

    TreeNode *root = new TreeNode(1);
    TreeNode *tmp = root;
    // tmp->left = new TreeNode(9);
    // tmp = tmp->left;
    // tmp->left = new TreeNode(4);
    // tmp->right = new TreeNode(4);
    // tmp = root;
    tmp->right = new TreeNode(2);
    tmp = tmp->right;
    // tmp->left = new TreeNode(15);
    tmp->right = new TreeNode(3);

    int targetSum = 6;

    cout << hasPathSum(root, targetSum) << endl;

    return 0;
}

bool hasPathSum(TreeNode* root, int targetSum) {

    if (root == nullptr)
        return false;

    if (root->left == nullptr && root->right == nullptr)
        return targetSum == root->val;

    return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
}