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

int threeSumClosest(vector<int>& nums, int target);

int main() {

    vector<int> nums = {-1,2,1,-4};
    int target = 1;

    cout << threeSumClosest(nums, target) << endl;

    return 0;
}

int threeSumClosest(vector<int>& nums, int target) {

    int n = nums.size();
    int closestSum = 0, minGap = INT_MAX;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {

        if (i > 0 && nums[i] == nums[i-1])
            continue;

        int j = i+1, k = n-1;
        while(j < k) {
            if (j > i+1 && nums[j] == nums[j-1])
                continue;

            int sum = nums[i]+nums[j]+nums[k];
            if (sum == target)
                return target;

            if (abs(sum-target) < abs(minGap)) {
                minGap = abs(sum-target);
                closestSum = sum;
            }

            if (sum > target) {
                int k0 = k-1;
                while(j < k0 && nums[k0] == nums[k])
                    --k0;
                k = k0;
            }

            if (sum < target) {
                int j0 = j+1;
                while(j0 < k && nums[j0] == nums[j])
                    ++j0;
                j = j0;
            }
        }
    }

    return closestSum;
}