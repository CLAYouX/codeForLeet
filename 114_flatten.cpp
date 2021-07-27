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

void flatten(TreeNode* root);

vector<int> levelOrder(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode *tmp = q.front();
            q.pop();
            ans.push_back(tmp->val);
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
    }

    return ans;
}

int main() {

    TreeNode *root = new TreeNode(1);
    TreeNode *tmp = root;
    tmp->left = new TreeNode(2);
    tmp = tmp->left;
    tmp->left = new TreeNode(3);
    tmp->right = new TreeNode(4);
    // tmp = tmp->left;
    // tmp->left = new TreeNode(7);
    // tmp->right = new TreeNode(2);
    tmp = root;
    tmp->right = new TreeNode(5);
    tmp = tmp->right;
    // tmp->left = new TreeNode(13);
    tmp->right = new TreeNode(6);
    // tmp = tmp->right;
    // tmp->left = new TreeNode(5);
    // tmp->right = new TreeNode(1);

    flatten(root);

    vector<int> ans = levelOrder(root);
    for (auto &i : ans)
        cout << i << " ";

    return 0;
}

void flatten(TreeNode* root) {

    if (root == nullptr)
        return;

    TreeNode *tmp = root;
    while(tmp != nullptr) {
        TreeNode *left = tmp->left;
        TreeNode *mostRight = left;
        if (mostRight == nullptr) {
            tmp = tmp->right;
            continue;
        }
        while(mostRight->right != nullptr)
            mostRight = mostRight->right;

        mostRight->right = tmp->right;
        tmp->right = left;
        tmp->left = nullptr;
        tmp = tmp->right;
    }

    return;
}