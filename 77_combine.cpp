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

vector<vector<int>> combine(int n, int k);

void dfs(vector<vector<int>> &ans, vector<int> &combination, int n, int k, int curr, int p) {

    if (curr == k) {
        ans.push_back(combination);
        return;
    }

    for (int i = p; i <= n; ++i) {
        combination.push_back(i);
        dfs(ans, combination, n, k, curr+1, i+1);
        combination.pop_back();
    }
}

int main() {

    int n = 4, k = 2;

    vector<vector<int>> ans = combine(n, k);
    for (auto &v : ans) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> combine(int n, int k) {

    // vector<vector<int>> ans;
    // vector<int> combination;

    // dfs(ans, combination, n, k, 0, 1);

    // return ans;

    vector<int> temp;
    vector<vector<int>> ans;

    // 初始化
    // 将 temp 中 [0, k - 1] 每个位置 i 设置为 i + 1，即 [0, k - 1] 存 [1, k]
    // 末尾加一位 n + 1 作为哨兵
    for (int i = 1; i <= k; ++i) {
        temp.push_back(i);
    }
    temp.push_back(n + 1);
    
    int j = 0;
    while (j < k) {
        ans.emplace_back(temp.begin(), temp.begin() + k);
        j = 0;
        // 寻找第一个 temp[j] + 1 != temp[j + 1] 的位置 t
        // 我们需要把 [0, t - 1] 区间内的每个位置重置成 [1, t]
        while (j < k && temp[j] + 1 == temp[j + 1]) {
            temp[j] = j + 1;
            ++j;
        }
        // j 是第一个 temp[j] + 1 != temp[j + 1] 的位置
        ++temp[j];
    }
    return ans;
}