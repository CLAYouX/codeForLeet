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

int maxPathSum(TreeNode* root);

int dfs(TreeNode *root, int &maxPath) {

    if (root == nullptr)
        return 0;

    int leftPath = dfs(root->left, maxPath);
    int rightPath = dfs(root->right, maxPath);

    int subPath = root->val;
    if (leftPath > 0)
        subPath += leftPath;
    if (rightPath > 0)
        subPath += rightPath;

    maxPath = max(maxPath, subPath);
    return max(root->val, max(root->val+leftPath, root->val+rightPath));
}

int main() {

    TreeNode *root = new TreeNode(-10);
    TreeNode *tmp = root;
    tmp->left = new TreeNode(9);
    tmp->right = new TreeNode(20);
    tmp = tmp->right;
    tmp->left = new TreeNode(15);
    tmp->right = new TreeNode(7);

    cout << maxPathSum(root) << endl;

    return 0;
}

int maxPathSum(TreeNode* root) {

    int maxPath = INT_MIN;
    dfs(root, maxPath);

    return maxPath;
}