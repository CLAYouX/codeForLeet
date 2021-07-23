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

int search(vector<int>& nums, int target);

int search(vector<int> &nums, int target, int left, int right) {
    if (left == right)
        return nums[left] == target? left : -1;

    int mid = left + (right-left) / 2;
    if (nums[left] <= nums[mid]) {
        if (target >= nums[left] && target <= nums[mid])
            return search(nums, target, left, mid);
        else
            return search(nums, target, mid+1, right);
    }else {
        if (target >= nums[mid] && target <= nums[right])
            return search(nums, target, mid, right);
        else
            return search(nums, target, left, mid-1);
    }

}

int main() {

    vector<int> nums;
    int target;

    return 0;
}

int search(vector<int>& nums, int target) {

    int n = nums.size();
    if (n == 0)
        return -1;

    return search(nums, target, 0, n-1);
}