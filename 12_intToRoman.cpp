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

string intToRoman(int num);

vector<pair<int, string>> mp = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
                                {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
                                {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

int main() {

    int num = 1994;

    cout << intToRoman(num) << endl;

    return 0;
}

string intToRoman(int num) {

    int n = mp.size();

    string ans = "";
    while(num) {
        int i = 0;
        for (; i < n; ++i) {
            if (num >= mp[i].first) {
                ans += mp[i].second;
                num -= mp[i].first;
                break;
            }
        }
    }

    return ans;
}