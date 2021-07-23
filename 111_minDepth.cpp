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

int minDepth(TreeNode* root);

int main() {

    TreeNode *root = new TreeNode(2);
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

    cout << minDepth(root) << endl;

    return 0;
}

int minDepth(TreeNode* root) {

    if (root == nullptr)
        return 0;

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if (left == 0 || right == 0)
        return max(left, right)+1;

    return min(left, right)+1;
}