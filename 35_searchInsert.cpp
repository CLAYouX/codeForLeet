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

int searchInsert(vector<int>& nums, int target);

int main() {

    vector<int> nums = {1,3,5,6};
    int target = 0;

    cout << searchInsert(nums, target) << endl;

    return 0;
}

int searchInsert(vector<int>& nums, int target) {

    int n = nums.size();
    if (n == 0)
        return 0;

    int left = 0, right = (int)nums.size()-1, ans = (int)nums.size();
    while(left <= right) {
        int mid = left + (right-left)/2;
        if (nums[mid] >= target) {
            right = mid - 1;
            ans = mid;
        }else {
            left = mid + 1;
        }
    }

    return ans;
}