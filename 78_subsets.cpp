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

vector<vector<int>> subsets(vector<int>& nums);

void dfs(vector<vector<int>> &ans, vector<int> &subset, vector<int> &nums, int cur, int p) {

    if (cur == nums.size()) {
        ans.push_back(subset);
        return;
    }

    ans.push_back(subset);

    for (int i = p; i < nums.size(); ++i) {
        subset.push_back(nums[i]);
        dfs(ans, subset, nums, cur+1, i+1);
        subset.pop_back();
    }
}

int main() {

    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = subsets(nums);
    for (auto &v : ans) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> subset;

    dfs(ans, subset, nums, 0, 0);

    return ans;
}