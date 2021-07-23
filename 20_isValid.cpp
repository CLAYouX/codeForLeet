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

bool isValid(string s);

int main() {

    string s = "{[]})";

    cout << isValid(s) << endl;

    return 0;
}

bool isValid(string s) {

    int n =s.size();
    if (n == 0)
        return true;

    stack<char> stk;
    for (int i = 0; i < n; ++i) {
        switch (s[i])
        {
        case '(':
        case '{':
        case '[':
            stk.push(s[i]);
            break;
        
        case ')':
            if (!stk.empty() && stk.top() == '(')
                stk.pop();
            else
                return false;
            break;

        case '}':
            if (!stk.empty() && stk.top() == '{')
                stk.pop();
            else
                return false;
            break;

        case ']':
            if (!stk.empty() && stk.top() == '[')
                stk.pop();
            else
                return false;
            break;
        }
    }

    return stk.empty();
}