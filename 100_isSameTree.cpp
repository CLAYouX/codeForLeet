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

bool isSameTree(TreeNode* p, TreeNode* q);

int main() {

    return 0;
}

bool isSameTree(TreeNode* p, TreeNode* q) {

    if (p == nullptr && q == nullptr)
        return true;
    else if (p == nullptr || q == nullptr)
        return false;
    else if (p->val != q->val)
        return false;
    else 
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}