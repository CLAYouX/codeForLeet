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

bool isSymmetric(TreeNode* root);

bool check(TreeNode *node1, TreeNode *node2) {
    if (node1 == nullptr && node2 == nullptr)
        return true;
    else if (node1 == nullptr || node2 == nullptr)
        return false;
    else if (node1->val != node2->val)
        return false;
    else
        return check(node1->left, node2->right) && check(node1->right, node2->left);
}

int main() {

    TreeNode *root = new TreeNode(1);
    TreeNode *tmp = root;
    tmp->left = new TreeNode(2);
    tmp = tmp->left;
    //tmp->left = new TreeNode(3);
    tmp->right = new TreeNode(3);
    tmp = root;
    tmp->right = new TreeNode(2);
    tmp = tmp->right;
    //tmp->left = new TreeNode(4);
    tmp->right = new TreeNode(3);

    cout << isSymmetric(root) << endl;

    return 0;
}

bool isSymmetric(TreeNode* root) {

    return check(root->left, root->right);
}