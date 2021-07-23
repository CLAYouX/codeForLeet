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

int firstMissingPositive(vector<int>& nums);

int main() {

    vector<int> nums = {1,1};

    cout << firstMissingPositive(nums) << endl;
    for (auto &i : nums)
        cout << i << " ";

    return 0;
}

int firstMissingPositive(vector<int>& nums) {

    int n = nums.size();

    if (n == 0)
        return 1;

    for (int i = 0; i < n; ++i) {
        while(nums[i] <= n && nums[i] > 0 && nums[i] != nums[nums[i]-1])
            swap(nums[i], nums[nums[i]-1]);
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] != i+1)
            return i+1;
    }

    return n+1;
}