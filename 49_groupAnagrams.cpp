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

vector<vector<string>> groupAnagrams(vector<string>& strs);

int main() {

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans = groupAnagrams(strs);
    for (auto &v : ans) {
        for (auto &s : v)
            cout << s << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    int n = strs.size();

    unordered_map<string, vector<string>> mp;

    for (auto &s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> ans;
    for (auto &p : mp)
        ans.push_back(p.second);

    return ans;
}