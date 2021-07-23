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

vector<vector<int>> fourSum(vector<int>& nums, int target);

int main() {

    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> ans = fourSum(nums, target);

    for (auto &v : ans) {
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {

    vector<vector<int>> ans;
    int n = nums.size();

    if (n == 0)
        return ans;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i-1] == nums[i])
            continue;

        for (int j = i+1; j < n; ++j) {
            if (j > i+1 && nums[j-1] == nums[j])
                continue;
            
            int p = n-1;
            int newTarget = target - nums[i] - nums[j];
            for (int k = j+1; k < n; ++k) {
                if (k > j+1 && nums[k-1] == nums[k])
                    continue;

                while(k < p && nums[k]+nums[p] > newTarget)
                    --p;

                if (k == p)
                    break;

                if (nums[k] + nums[p] == newTarget)
                    ans.push_back({nums[i], nums[j], nums[k], nums[p]});
            }
        }
    }

    return ans;
}