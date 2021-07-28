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

    vector<int> prices = {7,6,4,3,1};

    cout << maxProfit(prices) << endl;

    return 0;
}

int maxProfit(vector<int>& prices) {

    int n = prices.size();
    stack<int> stk;

    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        if (stk.empty() || prices[i] < stk.top())
            stk.push(prices[i]);
        else {
            maxProfit += prices[i]-stk.top();
            stk.pop();
            stk.push(prices[i]);
        }
    }

    return maxProfit;
}