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

bool isMatch(string s, string p);

int main() {

    string s = "acdcb", p = "a*c?b";

    cout << isMatch(s, p) << endl;

    return 0;
}

bool isMatch(string s, string p) {

    int m = s.size(), n = p.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    auto match = [&](int i, int j) {
        if (i == 0)
            return false;

        if (p[j-1] == '?')
            return true;

        return s[i-1] == p[j-1];
    };

    for (int i = 1; i <= n; ++i) {
        if (p[i - 1] == '*') {
            dp[0][i] = true;
        }
        else {
            break;
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*')
                dp[i][j] = dp[i][j-1] | dp[i-1][j];             
            else {
                if (match(i,j))
                    dp[i][j] |= dp[i-1][j-1];
            }
        }
    }

    for (auto &v : dp) {
        for (auto &t : v)
            cout << t << " ";
        cout << endl;
    }

    return dp[m][n];
}