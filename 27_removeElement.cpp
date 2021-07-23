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

int removeElement(vector<int>& nums, int val);

int main() {

    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    int len = removeElement(nums, val);

    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }

    return 0;
}

int removeElement(vector<int>& nums, int val) {

    int n = nums.size();

    if (n == 0)
        return 0;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != val) {
            nums[cnt++] = nums[i];
        }
    }

    return cnt;
}