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

bool isBalanced(TreeNode* root);

int getHeight(TreeNode *root) {
    if (root == nullptr)
        return 0;

    return max(getHeight(root->left), getHeight(root->right))+1;
}

int main() {

    TreeNode *root = new TreeNode(3);
    TreeNode *tmp = root;
    tmp->left = new TreeNode(9);
    // tmp = tmp->left;
    // tmp->left = new TreeNode(4);
    // tmp->right = new TreeNode(4);
    tmp = root;
    tmp->right = new TreeNode(20);
    tmp = tmp->right;
    tmp->left = new TreeNode(15);
    tmp->right = new TreeNode(7);

    cout << isBalanced(root) << endl;

    return 0;
}

bool isBalanced(TreeNode* root) {

    if (root == nullptr)
        return true;

    int leftTree = getHeight(root->left);
    int rightTree = getHeight(root->right);

    if (abs(leftTree-rightTree) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}