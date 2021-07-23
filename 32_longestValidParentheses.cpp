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

int longestValidParentheses(string s);

int main() {

    string s = "";

    cout << longestValidParentheses(s) << endl;

    return 0;
}

int longestValidParentheses(string s) {

    int n = s.size();
    
    int maxLength = 0;
    vector<int> dp(n);
    for (int i = 1; i < n; ++i) {
        if (s[i] == ')') {
            if (s[i-1] == '(')
                dp[i] = (i >= 2? dp[i-2] : 0) + 2;
            else if (i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '('){
                dp[i] = dp[i-1] + ((i-dp[i-1]) >= 2? dp[i-dp[i-1]-2] : 0) + 2;
            }
            maxLength = max(dp[i], maxLength);
        }
    }

    return maxLength;
}