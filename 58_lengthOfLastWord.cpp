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

int lengthOfLastWord(string s);

int main() {

    string s = "       ";

    cout << lengthOfLastWord(s) << endl;

    return 0;
}

int lengthOfLastWord(string s) {

    int n = s.size();
    if (n == 0)
        return 0;

    int lastLength = 0, wordLength = 0;
    for (int i = 0; i < n; ++i) {
        if (isalpha(s[i])) {
            ++wordLength;
        }else if (isspace(s[i])) {
            if (i > 0 && isalpha(s[i-1]))
                lastLength = wordLength;
            wordLength = 0;
        }
    }

    if (isalpha(s[n-1]))
        lastLength = wordLength;

    return lastLength;
}