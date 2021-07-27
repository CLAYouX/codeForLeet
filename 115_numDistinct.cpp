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

int numDistinct(string s, string t);

int main() {

    string s = "babgbag", t = "bag";

    cout << numDistinct(s, t) << endl;

    return 0;
}

int numDistinct(string s, string t) {

    int m = s.size(), n = t.size();
    if (m < n)
        return 0;

    unordered_map<char, int> um;
    for (auto &c : s)
        ++um[c];
    
    for (auto &c : t) {
        if (um.find(c) == um.end() || um[c] == 0)
            return 0;
        else
            --um[c];
    }

    vector<vector<long long>> dp(m+1, vector<long long>(n+1));

    for (int i = 0; i < n; ++i)
        dp[m][i] = 0;

    for (int i = 0; i <= m; ++i)
        dp[i][n] = 1;

    for (int i = m-1; i >= 0; --i) {
        for (int j = n-1; j >= 0; --j) {
            if (s[i] == t[j])
                dp[i][j] = dp[i+1][j] + dp[i+1][j+1];
            else
                dp[i][j] = dp[i+1][j];
        }
    }

    return dp[0][0];
}