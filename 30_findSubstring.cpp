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

vector<int> findSubstring(string s, vector<string>& words);

bool KMP(string haystack, string needle) {

    int n = haystack.size(), m = needle.size();

    if (m == 0 || n < m)
        return false;

    vector<int> next(n);
    for (int i = 1, j = 0; i < m; ++i) {
        while(j > 0 && needle[i] != needle[j])
            j = next[j-1];

        if (needle[i] == needle[j])
            ++j;

        next[i] = j;
    }

    for (int i = 0, j = 0; i < n; ++i) {
        while(j > 0 && haystack[i] != needle[j])
            j = next[j-1];

        if (haystack[i] == needle[j])
            ++j;

        if (j == m)
            return true;
    }

    return false;
}

int main() {

    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};

    vector<int> ans = findSubstring(s, words);
    for (auto &i : ans)
        cout << i << " ";

    return 0;
}

vector<int> findSubstring(string s, vector<string>& words) {

    vector<int> ans;
    int n = words.size();

    if (n == 0)
        return ans;

    int wordLen = words[0].size();

    unordered_map<string, int> mp1, mp2;
    for (auto &word : words)
        ++mp1[word];

    for (int i = 0; i + wordLen*n <= s.size(); ++i) {
        int j = 0;
        for (j = i; j < i + wordLen*n; j += wordLen) {
            string tmp = s.substr(j, wordLen);
            ++mp2[tmp];
            if (mp1[tmp] == 0)
                break;
            else {
                if (mp1[tmp] < mp2[tmp])
                    break;
            }
        }

        if (j == i + wordLen*n)
            ans.push_back(i);

        mp2.clear();
    }

    return ans;
}