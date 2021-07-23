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

vector<TreeNode*> generateTrees(int n);

vector<TreeNode*> generate(int left, int right) {

    if (left > right)
        return {nullptr};

    vector<TreeNode*> roots;
    for (int i = left; i <= right; ++i) {
        
        vector<TreeNode*> leftTrees = generate(left, i-1);
        vector<TreeNode*> rightTrees = generate(i+1, right);

        for (auto &l : leftTrees) {
            for (auto &r : rightTrees) {
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                roots.push_back(root);
            }
        }
    }

    return roots;
}

vector<int> inorderTraversal(TreeNode* root) {

    if (root == nullptr)
        return {};

    vector<int> ans;
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

    int n = 3;
    vector<TreeNode*> ans = generateTrees(n);

    for (auto &root : ans) {
        vector<int> order = inorderTraversal(root);
        for (auto &i : order) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<TreeNode*> generateTrees(int n) {

    if (n == 0)
        return {};

    vector<TreeNode*> ans = generate(1, n);

    return ans;
}