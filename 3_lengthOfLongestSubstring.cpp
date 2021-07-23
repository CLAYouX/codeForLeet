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

int lengthOfLongestSubstring(string s);

int main() {

    string s = "pwwkew";

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}

int lengthOfLongestSubstring(string s) {

    int n = s.size();
    if (!n)
        return 0;

    int tail = 0;
    int maxLength = 1;
    while(tail < n) {
        unordered_map<char, int> mp;
        mp[s[tail]] = tail;
        int prev = tail+1;
        for (; prev < n; ++prev) {
            if (mp.find(s[prev]) != mp.end()) {
                break;
            }else
                mp[s[prev]] = prev;
        }
        maxLength = max(maxLength, prev-tail);
        if (prev == n)
            break;
        tail = mp[s[prev]]+1;
    }

    return maxLength;
}