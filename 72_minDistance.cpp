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

int minDistance(string word1, string word2);

int main() {

    string word1 = "intention", word2 = "execution";

    cout << minDistance(word1, word2) << endl;

    return 0;
}

int minDistance(string word1, string word2) {

    int m = word1.size(), n = word2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i-1] == word2[j-1])
                dp[i-1][j-1] -= 1;

            dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
        }
    }

    return dp[m][n];
}