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

string minWindow(string s, string t);

int main() {

    string s = "a", t = "a";

    cout << minWindow(s, t) << endl;

    return 0;
}

string minWindow(string s, string t) {

    unordered_map<char, int> ori, cnt;

    auto check = [&]() {
        for (const auto &p : ori) {
            if (cnt[p.first] < p.second)
                return false;
        }
        return true; 
    };

    for (auto &c : t)
        ++ori[c];

    int l = 0, r = 0, ansL = -1, len = INT_MAX;
    while(r < s.size()) {
        if (ori.find(s[r]) != ori.end()){
            ++cnt[s[r]];
        }

        while(check() && l <= r) {
            if (r-l+1 < len) {
                len = r-l+1;
                ansL = l;
            }
            if (ori.find(s[l]) != ori.end()) {
                --cnt[s[l]];
            }
            ++l;
        }

        ++r;
    }

    return ansL == -1? "" : s.substr(ansL, len);
}