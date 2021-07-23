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

int strStr(string haystack, string needle);

int main() {

    string haystack = "aaa", needle = "aaaa";

    cout << strStr(haystack, needle) << endl;
    return 0;
}

int strStr(string haystack, string needle) {

    // int m = haystack.size(), n = needle.size();

    // if (n == 0)
    //     return 0;

    // if (m < n)
    //     return -1;

    // for (int i = 0; i < m-n+1; ++i) {
    //     int j = 0;
    //     for (; j < n && i + j < m; ++j) {
    //         if (haystack[i+j] != needle[j])
    //             break;
    //     }
    //     if (j == n)
    //         return i;

    // }

    // return -1;

    int n = haystack.size(), m = needle.size();

    if (m == 0)
        return 0;

    vector<int> next(n);
    for (int i = 1, j = 0; i < m; ++i) {
        while(j > 0 && needle[i] != needle[j])
            j = next[j-1];

        if (needle[j] == needle[i])
            ++j;

        next[i] = j;
    }

    for (int i = 0, j = 0; i < n; ++i) {
        while(j > 0 && haystack[i] != needle[j])
            j = next[j-1];
        
        if (haystack[i] == needle[j])
            ++j;

        if (j == m)
            return i-m+1;
    }

    return -1;
}