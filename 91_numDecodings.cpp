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


int numDecodings(string s);

int main() {

    string s = "10011";

    cout << numDecodings(s) << endl;
    return 0;
}

int numDecodings(string s) {

    int n = s.size();

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = (s[0] == '0'? 0 : 1);
    for (int i = 2; i <= n; ++i) {
        int num = s[i-1]-'0';
        if (num != 0)
            dp[i] += dp[i-1];

        if (s[i-2] != '0') {
            num = (s[i-2]-'0')*10 + s[i-1]-'0';
            if (num <= 26 && num > 0)
                dp[i] += dp[i-2];
        }
    }

    return dp[n];
}