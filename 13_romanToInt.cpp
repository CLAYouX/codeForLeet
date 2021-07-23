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

int romanToInt(string s);

unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100},
                               {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

int main() {

    string s = "III";

    cout << romanToInt(s) << endl;
    return 0;
}

int romanToInt(string s) {

    int ans = 0;
    
    for (int i = s.size()-1; i >= 0; --i) {
        if (i < s.size()-1 && mp[s[i]] < mp[s[i+1]])
            ans -= mp[s[i]];
        else
            ans += mp[s[i]];
    }

    return ans;
}