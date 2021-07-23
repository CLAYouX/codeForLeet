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

vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

void dfs(vector<vector<int>> &ans, vector<int> &combination, vector<int> &candidates, int target, int idx) {
    
    if (target == 0) {
        ans.push_back(combination);
        return;
    }
    
    for (int i = idx; i < candidates.size(); ++i) {
        if (target - candidates[i] < 0)
            break;

        if (i > idx && candidates[i] == candidates[i-1])
            continue;

        combination.push_back(candidates[i]);
        dfs(ans, combination, candidates, target-candidates[i], i+1);
        combination.pop_back();
    }
}

int main() {

    vector<int> candidates = {2,5,2,1,2};
    int target = 5;

    vector<vector<int>> ans = combinationSum2(candidates, target);
    for (auto &v : ans) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> combination;

    dfs(ans, combination, candidates, target, 0);
    
    return ans;
}