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

vector<vector<int>> permute(vector<int>& nums);

void dfs(vector<vector<int>> &ans, vector<int> &permutation, vector<int> &nums, vector<int> &visited, int curr) {

    if (curr == nums.size()) {
        ans.push_back(permutation);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i] == 0) {
            visited[i] = 1;
            permutation.push_back(nums[i]);
            dfs(ans, permutation, nums, visited, curr+1);
            permutation.pop_back();
            visited[i] = 0;
        }
    }
}

int main() {

    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = permute(nums);
    for (auto &v : ans) {
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> permute(vector<int>& nums) {

    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> permutation;

    if (n == 0)
        return ans;

    vector<int> visited(n, 0);
    dfs(ans, permutation, nums, visited, 0);

    return ans;
}