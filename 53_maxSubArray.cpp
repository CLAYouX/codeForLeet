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

int maxSubArray(vector<int>& nums);

int main() {

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray(nums) << endl;

    return 0;
}

int maxSubArray(vector<int>& nums) {

    int n = nums.size();

    vector<int> f(n+1);
    f[0] = 0;
    int maxSum = INT_MIN;
    
    for (int i = 1; i <= n; ++i) {
        f[i] = max(nums[i-1], f[i-1]+nums[i-1]);
        maxSum = max(maxSum, f[i]);
    }

    return maxSum;
}