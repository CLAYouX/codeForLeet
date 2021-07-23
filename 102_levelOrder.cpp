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

vector<vector<int>> levelOrder(TreeNode* root);

int main() {

    TreeNode *root = new TreeNode(1);
    TreeNode *tmp = root;
    tmp->left = new TreeNode(2);
    tmp = tmp->left;
    tmp->left = new TreeNode(3);
    tmp->right = new TreeNode(4);
    tmp = root;
    tmp->right = new TreeNode(2);
    tmp = tmp->right;
    tmp->left = new TreeNode(4);
    tmp->right = new TreeNode(3);

    vector<vector<int>> ans = levelOrder(root);
    for (auto &v : ans) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
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