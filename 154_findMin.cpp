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

int findMin(vector<int>& nums);

int main() {

    vector<int> nums = {4,5,6,7,0,1,4};

    cout << findMin(nums) << endl;

    return 0;
}

int findMin(vector<int>& nums) {

    // int n = nums.size();
    // int left = 0, right = n-1;
    // while(left < right) {
    //     while(left < right && nums[left+1] == nums[left]) {
    //         ++left;
    //     }

    //     while(left <  right && nums[right-1] == nums[right]) {
    //         --right;
    //     }

    //     int mid = left + (right-left) / 2;
    //     if (nums[mid] < nums[right])
    //         right = mid;
    //     else
    //         left = mid + 1;
    // }

    // return left < n ? nums[left] : nums[right];

    int n = nums.size();
    int left = 0, right = n-1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[right])
            right = mid;
        else if (nums[mid] > nums[right])
            left = mid + 1;
        else 
            right -= 1;
    }

    return nums[left];
}