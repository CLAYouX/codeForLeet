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

void sortColors(vector<int>& nums);

int main() {

    vector<int> nums = {2,0,1};

    sortColors(nums);
    for (auto &i : nums)
        cout << i << " ";
    return 0;
}

void sortColors(vector<int>& nums) {

    int n = nums.size();
    int r = 0, w = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0)
            ++r;
        else if (nums[i] == 1)
            ++w;
        else
            ++b;
    }

    for (int i = 0 ; i < n; ++i) {
        if (i < r)
            nums[i] = 0;
        else if (i < r+w)
            nums[i] = 1;
        else 
            nums[i] = 2;
    }

}