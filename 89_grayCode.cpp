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

vector<int> grayCode(int n);

int main() {

    int n = 3;

    vector<int> ans = grayCode(n);
    for (auto &i : ans)
        cout << i << " ";

    return 0;
}

vector<int> grayCode(int n) {

    vector<int> ans;
    ans.push_back(0);

    for (int i = 0; i < n; ++i) {
        int len = ans.size();
        for (int j = len-1; j >= 0; --j) {
            ans.push_back(ans[j]+pow(2,i));
        }
    }

    return ans;
}