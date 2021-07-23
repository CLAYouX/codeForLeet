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

vector<string> generateParenthesis(int n);

void dfs(vector<string> &ans, string &parenthesis, int left, int right) {
    if (left == right && left == 0) {
        ans.push_back(parenthesis);
        return;
    }

    if (left > right)
        return ;

    if (left > 0) {
        parenthesis.push_back('(');
        dfs(ans, parenthesis, left-1, right);
        parenthesis.pop_back();
    }
    
    if (right > 0) {
        parenthesis.push_back(')');
        dfs(ans, parenthesis, left, right-1);
        parenthesis.pop_back();
    } 
}

int main() {

    int n = 4;

    vector<string> ans = generateParenthesis(n);

    for (auto &s : ans)
        cout << s << endl;

    return 0;
}

vector<string> generateParenthesis(int n) {

    vector<string> ans;
    string parenthesis = "";

    dfs(ans, parenthesis, n, n);

    return ans;
}