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

string countAndSay(int n);

int main() {

    int n = 5;

    cout << countAndSay(n) << endl;

    return 0;
}

string countAndSay(int n) {

    if (n == 1)
        return string("1");

    string last = "1";
    string ans;
    for (int i = 1; i < n; ++i) {
        int len = last.size();
        char pre = last[0];
        int cnt = 1;
        for (int j = 1; j < len; ++j) {
            if (last[j] == pre) {
                ++cnt;
            }else {
                ans.push_back(cnt+'0');
                ans.push_back(pre);
                pre = last[j];
                cnt = 1;
            }
        }

        ans.push_back(cnt+'0');
        ans.push_back(pre);
        last = ans;
        ans = "";
    }

    return last;
}