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

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);

int main() {

    vector<vector<int>> intervals;
    vector<int> newInterval;

    return 0;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    int n = intervals.size();
    vector<vector<int>> ans;

    if (n == 0) {
        ans.push_back(newInterval);
        return ans;
    }

    for (int i = 0; i < n; ++i) {
        int L = intervals[i][0], R = intervals[i][1];

        if (ans.empty() && L >= newInterval[1])
            ans.push_back(newInterval);

        if (R < newInterval[0] || L > newInterval[1]) {
            ans.push_back({L,R});
        }else {
            if (ans.back()[1] < L) {

            } 
        }
    }

    return ans;
}