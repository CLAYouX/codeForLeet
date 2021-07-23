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

vector<vector<int>> merge(vector<vector<int>>& intervals);

bool compare(vector<int> &v1, vector<int> &v2) {
    if (v1[0] == v2[0])
        return v1[1] < v2[1];

    return v1[0] < v2[0];
}

int main() {

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ans = merge(intervals);
    for (auto &v : ans) {
        cout << v[0] << " " << v[1] << endl;
    }

    return 0;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end(), compare);

    int n = intervals.size();
    vector<vector<int>> ans;
    int start = intervals[0][0], end = intervals[0][1];
    for (int i = 1; i < n; ++i) {
        if (intervals[i][0] > end) {
            ans.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }else {
            end = max(end, intervals[i][1]);
        }
    }

    ans.push_back({start, end});
    return ans;
}