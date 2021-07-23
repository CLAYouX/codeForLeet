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

int removeDuplicates(vector<int>& nums);

int main() {

    vector<int> nums = {1,1,1,2,2,3};

    int n = removeDuplicates(nums);
    for (int i = 0; i < n; ++i)
        cout << nums[i] << endl;

    return 0;
}

int removeDuplicates(vector<int>& nums) {

    int n = nums.size();
    if (n < 3)
        return n;

    int ans = 2;
    for (int i = 2; i < n; ++i) {
        if (nums[ans-2] != nums[i]) {
            nums[ans] = nums[i];
            ++ans;
        }
    }

    return ans;
}