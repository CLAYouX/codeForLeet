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

vector<vector<int>> levelOrderBottom(TreeNode* root);

int main() {


    return 0;
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {

    auto levelOrder = vector<vector<int>>();
    if (!root) {
        return levelOrder;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto level = vector<int>();
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        levelOrder.push_back(level);
    }
    reverse(levelOrder.begin(), levelOrder.end());
    return levelOrder;

}