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

void nextPermutation(vector<int>& nums);

int main() {

    vector<int> nums = {1,1,2,2,1};

    nextPermutation(nums);
    for (auto &i : nums)
        cout << i << " ";

    return 0;
}

void nextPermutation(vector<int>& nums) {

    int n = nums.size();

    if (n <= 1)
        return;

    int index = n;
    for (int i = n-1; i > 0; --i) {
        if (nums[i-1] < nums[i]) {
            index = i-1;
            break;
        }
    }

    if (index == n) {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n-1; n > index; --i) {
        if (nums[i] > nums[index]) {
            swap(nums[i], nums[index]);
            break;
        }
    }

    reverse(nums.begin()+index+1, nums.end());
}