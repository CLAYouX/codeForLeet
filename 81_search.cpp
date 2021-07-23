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

bool search(vector<int>& nums, int target);

int main() {

    vector<int> nums = {1,0,1,1,1};
    int target = 0;

    cout << search(nums, target) << endl;
    return 0;
}

bool search(vector<int>& nums, int target) {

    int n = nums.size();
    if (n == 0)
        return false;

    if (n == 1)
        return nums[0] == target;

    int l = 0, r = n-1;
    while(l <= r) {

        int mid = l + (r-l)/2;
        if (nums[mid] == target)
            return true;

        if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
            ++l;
            --r;
        }else if (nums[l] <= nums[mid]) {
            if (target >= nums[l] && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }else {
            if (target > nums[mid] && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    return false;
}