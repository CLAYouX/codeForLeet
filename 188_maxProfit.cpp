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

int maxProfit(int k, vector<int>& prices);

int main() {


    return 0;
}

int maxProfit(int k, vector<int>& prices) {

    int n = prices.size();
    
    vector<vector<int>> buy(n, vector<int>(k+1));
    vector<vector<int>> sell(n, vector<int>(k+1));

    buy[0][0] = -prices[0];
    sell[0][0] = 0;
    for (int i = 1; i < n; ++i) {
        buy[0][i] = sell[0][i] = INT_MIN/2;
    }

    for (int i = 1; i < n; ++i) {
        buy[i][0] = max(buy[i-1][0], sell[i-1][0]-prices[i]);
        for (int j = 1; j <= k; ++j) {
            buy[i][j] = max(buy[i-1][j], sell[i-1][j]-prices[i]);
            sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);   
        }
    }

    return *max_element(sell[n-1].begin(), sell[n-1].end());
}