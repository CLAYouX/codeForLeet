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

bool isPalindrome(string s);

int main() {

    string s = "a.";

    cout << isPalindrome(s) << endl;

    return 0;
}

bool isPalindrome(string s) {

    int n = s.size();
    int left = 0, right = n - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) {
            ++left;
        }
        while (left < right && !isalnum(s[right])) {
            --right;
        }
        if (left < right) {
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            ++left;
            --right;
        }
    }
    return true;
}