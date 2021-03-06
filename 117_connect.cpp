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

void handle(Node *&last, Node *&p, Node *&nextStart) {
    if (last)
        last->next = p;

    if (!nextStart)
        nextStart = p;

    last = p;
}

int main() {

    return 0;
}

Node* connect(Node* root) {

    if (root == nullptr)
        return root;

    Node *leftMost = root;
    while(leftMost != nullptr) {
        Node *nextStart = nullptr, *last = nullptr;
        for (Node *p = leftMost; p != nullptr; p = p->next) {
            if (p->left != nullptr) {
                handle(last, p->left, nextStart);
            }
            if (p->right != nullptr) {
                handle(last, p->right, nextStart);
            }
        }

        leftMost = nextStart;
    }

    return root;
}