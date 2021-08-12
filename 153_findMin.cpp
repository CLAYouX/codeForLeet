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

    vector<int> nums = {3,4,5,1,2};

    cout << findMin(nums) << endl;

    return 0;
}

int findMin(vector<int>& nums) {

    int n = nums.size();
    int left = 0, right = n-1;
    while(left < right) {
        int mid = left + (right-left) / 2;
        if (nums[mid] < nums[right])
            right = mid;
        else
            left = mid + 1;
    }

    return nums[left];
}