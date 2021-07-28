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

int maxProfit(vector<int>& prices);

int main() {

    vector<int> prices = {3,3,5,0,0,3,1,4};

    cout << maxProfit(prices) << endl;

    return 0;
}

int maxProfit(vector<int>& prices) {

    int n = prices.size();
    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;

    for (int i = 1; i < n; ++i) {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1+prices[i]);
        buy2 = max(buy2, sell1-prices[i]);
        sell2 = max(sell2, buy2+prices[i]);
    }

    return sell2;
}