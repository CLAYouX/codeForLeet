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

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int len = removeDuplicates(nums);

    for (int i = 0; i < len; ++i)
        cout << nums[i] << " ";

    return 0;
}

int removeDuplicates(vector<int>& nums) {

    int n = nums.size();
    if (n == 0)
        return 0;

    int preNum = nums[0], cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] != preNum) {
            preNum = nums[i];
            nums[cnt++] = nums[i];
        }
    }

    return cnt;
}