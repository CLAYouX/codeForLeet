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

int maxDepth(TreeNode *root);

int main() {

    TreeNode *root = new TreeNode(1);
    TreeNode *tmp = root;
    tmp->left = new TreeNode(2);
    // tmp = tmp->left;
    // tmp->left = new TreeNode(4);
    // tmp->right = new TreeNode(4);
    tmp = root;
    tmp->right = new TreeNode(3);
    tmp = tmp->right;
    // tmp->left = new TreeNode(15);
    tmp->right = new TreeNode(5);

    cout << maxDepth(root) << endl;

    return 0;
}

int maxDepth(TreeNode *root) {

    if (root == nullptr)
        return 0;

    int leftTreeDepth = maxDepth(root->left);
    int rightTreeDepth = maxDepth(root->right);

    return max(leftTreeDepth, rightTreeDepth) + 1;
}