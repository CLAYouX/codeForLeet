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

    vector<int> prices = {7,1,5,3,6,4};

    cout << maxProfit(prices) << endl;

    return 0;
}

int maxProfit(vector<int>& prices) {

    int n = prices.size();
    vector<int> leftMin(n);

    leftMin[0] = prices[0];
    for (int i = 1; i < n; ++i) {
        leftMin[i] = min(leftMin[i-1], prices[i]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxProfit = max(maxProfit, prices[i]-leftMin[i]);
    }

    return maxProfit;
}