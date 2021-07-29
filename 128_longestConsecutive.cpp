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

int longestConsecutive(vector<int>& nums);

int main() {

    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

    cout << longestConsecutive(nums) << endl;

    return 0;
}

int longestConsecutive(vector<int>& nums) {

    int n = nums.size();
    if (n == 0)
        return 0;
    sort(nums.begin(), nums.end());

    int longest = 1, seq = 1;
    int startIdx = 0, pre = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] == pre)
            continue;
        if (nums[i] != pre+1) {
            startIdx = i;
            pre = nums[i];
            seq = 1;
            continue;
        }
        pre = nums[i];
        ++seq;
        longest = max(longest, seq);
    }

    return longest;
}