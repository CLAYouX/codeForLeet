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

vector<string> letterCombinations(string digits);

unordered_map<char, vector<char>> mp = {{'2', {'a','b','c'}}, {'3', {'d','e','f'}},
                                        {'4', {'g','h','i'}}, {'5', {'j','k','l'}},
                                        {'6', {'m','n','o'}}, {'7', {'p','q','r','s'}},
                                        {'8', {'t','u','v'}}, {'9', {'w','x','y','z'}}};

void dfs(vector<string> &combinations, string &combination, string &digits, int n, int curr) {
    if (curr == n) {
        combinations.push_back(combination);
        return;
    }

    vector<char> alpha = mp[digits[curr]];
    for (int i = 0; i < alpha.size(); ++i) {
        combination.push_back(alpha[i]);
        dfs(combinations, combination, digits, n, curr+1);
        combination.pop_back();
    }
}

int main() {

    string digits = "";

    vector<string> ans = letterCombinations(digits);

    for (auto &s : ans)
        cout << s << endl;

    return 0;
}

vector<string> letterCombinations(string digits) {

    int n = digits.size();

    if (n == 0)
        return {};

    vector<string> ans;
    string combination;

    dfs(ans, combination, digits, n, 0);

    return ans;
}