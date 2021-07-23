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

vector<int> searchRange(vector<int>& nums, int target);

int searchLeft(vector<int> &nums, int target, int left, int right) {

    if (left >= right)
        return nums[left] == target? left : -1;

    int mid = left + (right-left)/2;
    if (nums[mid] < target)
        return searchLeft(nums, target, mid+1, right);
    else
        return searchLeft(nums, target, left, mid);
}

int searchRight(vector<int> &nums, int target, int left, int right) {

    if (left >= right)
        return nums[left] == target? nums.size() : left;

    int mid = left + (right-left)/2;
    if (nums[mid] <= target)
        return searchRight(nums, target, mid+1, right);
    else
        return searchRight(nums, target, left, mid);
}

int main() {

    vector<int> nums = {8,8,8,8,8};
    int target = 8;

    vector<int> ans = searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}

vector<int> searchRange(vector<int>& nums, int target) {

    int n = nums.size();
    if (n == 0)
        return vector<int>{-1, -1};

    int left = searchLeft(nums, target, 0, n-1);
    int right = searchRight(nums, target, 0, n-1);
    cout << right << endl;

    if (left == -1)
        return vector<int>{left, -1};
    else if (right == -1)
        return vector<int>{left, n-1};
    else
        return vector<int>{left, right-1};
}