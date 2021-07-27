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

vector<vector<int>> generate(int numRows);

int main() {

    int nums = 5;

    vector<vector<int>> ans = generate(nums);

    for (auto &v : ans) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    if (numRows == 0)
        return ans;

    for (int i = 0; i < numRows; ++i) {
        vector<int> row;
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i)
                row.push_back(1);
            else
                row.push_back(ans[i-1][j-1]+ans[i-1][j]);
        }
        ans.push_back(row);
    }

    return ans;
}