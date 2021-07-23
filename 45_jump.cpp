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

int jump(vector<int>& nums);

int main() {

    vector<int> nums = {1,1,1,1,4};

    cout << jump(nums) << endl;

    return 0;
}

int jump(vector<int>& nums) {

    int n = nums.size();
    
    vector<int> dis(n);
    for (int i = 0; i < n; ++i) {
        dis[i] = i + nums[i];
    }

    int pre = n-1, cnt = 0;
    while(pre) {
        for (int i = 0; i < pre; ++i) {
            if (dis[i] >= pre) {
                pre = i;
                ++cnt;
                break;
            }
        }
    }

    return cnt;
}