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

bool canJump(vector<int>& nums);

int main() {

    vector<int> nums = {0,2,3};

    cout << canJump(nums) << endl;

    return 0;
}

bool canJump(vector<int>& nums) {

    int n = nums.size();
    int maxPosition = 0, end = 0;

    for (int i = 0; i < n-1; ++i) {
        if (i <= end) {
            maxPosition = max(maxPosition, i+nums[i]);
            if (i == end)
                end = maxPosition;
        }else
            return false;
    }

    return maxPosition >= n-1;
}