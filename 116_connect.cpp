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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root);

void dfs(Node *parent, Node *root) {
    if (root->left == nullptr)
        return;

    Node *uncle = root->next;

    root->left->next = root->right;
    if (uncle)
        root->right->next = uncle->left;

    dfs(root, root->left);
    dfs(root, root->right);
}

int main() {

    Node *root = new Node(1);
    Node *tmp = root;
    tmp->left = new Node(2);
    tmp = tmp->left;
    tmp->left = new Node(4);
    tmp->right = new Node(5);
    tmp = root;
    tmp->right = new Node(3);
    tmp = tmp->right;
    tmp->left = new Node(6);
    tmp->right = new Node(7);

    connect(root);

    return 0;
}

Node* connect(Node* root) {

    if (root == nullptr)
        return nullptr;

    dfs(root, root);
    return root;
}