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

vector<vector<int>> combinationSum(vector<int>& candidates, int target);

void dfs(vector<vector<int>> &ans, vector<int> &combination, vector<int> &candidates, int curr, int sum, int target) {

    if (sum == target) {
        ans.push_back(combination);
        return;
    }

    int residue = target - sum;

    for (int i = curr; i < candidates.size(); ++i) {
        if (candidates[i] > residue)
            break;

        combination.push_back(candidates[i]);
        dfs(ans, combination, candidates, i, sum+candidates[i], target);
        combination.pop_back();
    }
}

int main() {

    vector<int> candidates = {2,3,5};
    int target = 8;

    vector<vector<int>> ans = combinationSum(candidates, target);
    for (auto &v : ans) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> combination;

    dfs(ans, combination, candidates, 0, 0, target);

    return ans;
}