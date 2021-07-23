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

string longestCommonPrefix(vector<string>& strs);

string longestCommonPrefix(vector<string> &strs, int left, int right) {

    if (left == right)
        return strs[left];

    int mid = left + (right - left) / 2;

    string leftLCP = longestCommonPrefix(strs, left, mid);
    string rightLCP = longestCommonPrefix(strs, mid+1, right);

    string LCP = "";
    int i = 0, j = 0;
    while(i < leftLCP.size() && j < rightLCP.size() && leftLCP[i] == rightLCP[j]) {
        LCP += leftLCP[i];
        ++i;
        ++j;
    }
    
    return LCP;
}

int main() {

    vector<string> strs = {"dog","racecar","car"};

    cout << longestCommonPrefix(strs) << endl;

    return 0;
}

string longestCommonPrefix(vector<string>& strs) {

    int n = strs.size();

    return longestCommonPrefix(strs, 0, n-1);
}