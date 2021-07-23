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

string longestPalindrome(string s);

int expandFromCenter(string s, int left, int right) {
    while(left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }

    return right-left-1;
}

int main() {

    string s = "bb";

    cout << longestPalindrome(s) << endl;

    return 0;
}

string longestPalindrome(string s) {

    // 动态规划
    // int n = s.size();
    // if (n < 2)
    //     return s;

    // vector<vector<int>> dp(n, vector<int>(n));

    // for (int i = 0; i < n; ++i) {
    //     dp[i][i] = 1;
    // }

    // int maxLength = 1, begin = 0;
    // string ans = "";
    // for (int l = 1; l < n; ++l) {
    //     for (int i = 0; i+l < n; ++i) {
    //         int j = i+l;

    //         if (l == 1) {
    //             dp[i][j] = (s[i] == s[j]);
    //         }else {
    //             dp[i][j] = (dp[i+1][j-1] && (s[i] == s[j]));
    //         }

    //         if (dp[i][j] && l+1 > maxLength) {
    //             maxLength = l + 1;
    //             begin = i;
    //         }
    //     }
    // }

    // return s.substr(begin, maxLength);

    int n = s.size();
    if (n < 2)
        return s;

    int left = 0, length = 0;
    for (int i = 0; i < n; ++i) {
        int len1 = expandFromCenter(s, i, i);
        int len2 = expandFromCenter(s, i, i+1);
        int len = max(len1, len2);

        if (len > length) {
            left = i - (len-1) / 2;
            length = len;
        }
    }

    return s.substr(left, length);
}