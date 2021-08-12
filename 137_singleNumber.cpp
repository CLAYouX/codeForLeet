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

int singleNumber(vector<int>& nums);

int main() {

    vector<int> nums = {0,1,0,1,0,1,99};

    cout << singleNumber(nums) << endl;

    return 0;
}

int singleNumber(vector<int>& nums) {

    vector<int> mask(32, 0);

    for (int i = 0; i < nums.size(); ++i) {
        int bitMask = 1;
        for (int j = 31; j >= 0; --j) {
            if (nums[i] & bitMask)
                mask[j] += 1;

            bitMask = bitMask << 1;
        }
    }

    int result = 0;
    for (int i = 0; i < 32; ++i) {
        result = result << 1;
        result += (mask[i]%3);
    }

    return result;
}