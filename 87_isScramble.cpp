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

bool isScramble(string s1, string s2);


int main() {

    string s1 = "great", s2 = "rgeat";

    cout << isScramble(s1, s2) << endl;

    return 0;
}

bool isScramble(string s1, string s2) {

    if (s1.size() != s2.size())
        return false;

    int n = s1.size();
    int dp[30][30][31] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j][1] = (s1[i] == s2[j]);
        }
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n-len; ++i) {
            for (int j = 0; j <= n-len; ++j) {
                for (int k = 1; k <= len-1; ++k) {
                    if (dp[i][j][k] && dp[i+k][j+k][len-k]) {
                        dp[i][j][len] = 1;
                        break;
                    }

                    if (dp[i][j+len-k][k] && dp[i+k][j][len-k]) {
                        dp[i][j][len] = 1;
                        break;
                    }
                }
            }
        }
    }

    return dp[0][0][n];
}