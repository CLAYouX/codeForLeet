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

vector<vector<int>> subsetsWithDup(vector<int>& nums);

void dfs(vector<vector<int>> &ans, vector<int> &combiantion, vector<int> &nums, vector<int> &visited, int curr) {
    if (curr == nums.size()) {
        ans.push_back(combiantion);
        return;
    }   

    ans.push_back(combiantion);

    for (int i = curr; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1] && !visited[i-1])
            continue;

        combiantion.push_back(nums[i]);
        visited[i] = 1;
        dfs(ans, combiantion, nums, visited, i+1);
        visited[i] = 0;
        combiantion.pop_back();
    }
}

int main() {

    vector<int> nums = {1,2,2};

    vector<vector<int>> ans = subsetsWithDup(nums);
    
    for (auto &v : ans) {
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> combination;

    int n = nums.size();
    if (n == 0)
        return ans;

    vector<int> visited(n, 0);
    sort(nums.begin(), nums.end());
    dfs(ans, combination, nums, visited, 0);

    return ans;
}