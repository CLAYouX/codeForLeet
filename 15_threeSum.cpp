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

vector<vector<int>> threeSum(vector<int>& nums);

int main() {

    vector<int> nums = {3,0,-2,-1,1,2};

    vector<vector<int>> ans = threeSum(nums);

    for (auto &v : ans) {
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> threeSum(vector<int>& nums) {

    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] == nums[i-1])
            continue;

        int k = n-1;
        for (int j = i+1; j < n; ++j) {
            
            if (j > i+1 && nums[j-1] == nums[j])
                continue;

            while (j < k && nums[i]+nums[j]+nums[k] > 0)
                --k;

            if (j == k)
                break;

            if (nums[i]+nums[j]+nums[k] == 0)
                ans.push_back({nums[i], nums[j], nums[k]});
        }
    }

    return ans;
}