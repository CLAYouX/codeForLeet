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

int sumNumbers(TreeNode* root);

void dfs(vector<int> &pathSum, int path, TreeNode *root) {
    if (root->left == nullptr && root->right == nullptr) {
        path = path*10 + root->val;
        pathSum.push_back(path);
        return;
    }

    path = path*10 + root->val;
    dfs(pathSum, path, root->left);
    dfs(pathSum, path, root->right);
}

int main() {

    TreeNode *root = new TreeNode(4);
    TreeNode *tmp = root;
    tmp->left = new TreeNode(9);
    tmp->right = new TreeNode(0);
    tmp = tmp->left;
    tmp->left = new TreeNode(5);
    tmp->right = new TreeNode(1);

    cout << sumNumbers(root) << endl;

    return 0;
}

int sumNumbers(TreeNode* root) {

    if (root == nullptr)
        return 0;

    vector<int> pathSum;
    dfs(pathSum, 0, root);

    int sum = 0;
    for (auto path : pathSum)
        sum += path;

    return sum;
}