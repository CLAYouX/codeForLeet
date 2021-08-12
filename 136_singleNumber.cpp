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

int singleNumber(vector<int>& nums);

int main() {

    vector<int> nums = {4,1,2,1,2};

    cout << singleNumber(nums) << endl;

    return 0;
}

int singleNumber(vector<int>& nums) {

    int ans = nums[0];
    for (int i = 1; i < nums.size(); ++i)
        ans ^= nums[i];

    return ans;
}