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

vector<int> twoSum(vector<int>& nums, int target);

int main() {

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {

    // int n = nums.size();

    // if (n == 0)
    //     return vector<int>();

    // sort(nums.begin(), nums.end());

    // vector<int> ans;
    // int left = 0, right = n-1;
    // while(left < right) {

    //     while (left > 0 && left < right && nums[left-1] == nums[left])
    //         ++left;

    //     while (right < n-1 && left < right && nums[right+1] == nums[right])
    //         --right;

    //     int sum = nums[left] + nums[right];
    //     if (sum == target) {
    //         ans.push_back(left);
    //         ans.push_back(right);
    //         break;
    //     }else if (sum < target) {
    //         ++left;
    //     }else {
    //         --right;
    //     }
    // }

    // return ans;

    int n = nums.size();

    if (n == 0)
        return vector<int>();

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (target == nums[i]+nums[j]) {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
        if (!ans.empty())
            break;
    }

    return ans;
}