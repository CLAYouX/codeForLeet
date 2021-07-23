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

string convert(string s, int numRows);

int main() {

    string s = "A";
    int numRows = 3;

    cout << convert(s, numRows) << endl;

    return 0;
}

string convert(string s, int numRows) {

    int n = s.size();

    vector<string> ans(numRows);
    int row = 0, sign = 1;

    for (int i = 0; i < n; ++i) {
        ans[row].push_back(s[i]);
        if (row == numRows - 1) {
            sign = -1;
        } else if (row == 0) {
            sign = 1;
        }
        row += sign;
    }

    string zSrring;
    for (auto &ss : ans) 
        zSrring += ss;

    return zSrring;
}