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

bool isNumber(string s);

enum State {INIT, SIGN, POINT, POINT_WITHOUT_INT, DECIMAL, INT, EXP, EXP_SIGN, EXP_NUM};

enum CharType {CHAR_NUMBER, CHAR_EXP, CHAR_POINT, CHAR_SIGN, CHAR_ILLEGAL};

CharType toCharType(char ch) {
    if (ch >= '0' && ch <= '9') {
        return CHAR_NUMBER;
    } else if (ch == 'e' || ch == 'E') {
        return CHAR_EXP;
    } else if (ch == '.') {
        return CHAR_POINT;
    } else if (ch == '+' || ch == '-') {
        return CHAR_SIGN;
    } else {
        return CHAR_ILLEGAL;
    }
}

int main() {

    string s = "0e";

    cout << isNumber(s) << endl;
    return 0;
}

bool isNumber(string s) {

    State curr = INIT;
    for (int i = 0; i < s.size(); ++i) {
        CharType type = toCharType(s[i]);
        switch (type)
        {
        case CHAR_NUMBER:
            if (curr == INIT || curr == SIGN || curr == INT)
                curr = INT;
            else if (curr == POINT || curr == DECIMAL || curr == POINT_WITHOUT_INT)
                curr = DECIMAL;
            else if (curr == EXP || curr == EXP_NUM || curr == EXP_SIGN)
                curr = EXP_NUM;
            else
                return false;
            break;
        
        case CHAR_EXP:
            if (curr == INT || curr == DECIMAL)
                curr = EXP;
            else
                return false;
            break;

        case CHAR_POINT:
            if (curr == INIT || curr == SIGN)
                curr = POINT_WITHOUT_INT;
            else if (curr == INT)
                curr = POINT;
            else
                return false;
            break;

        case CHAR_SIGN:
            if (curr == INIT)
                curr = SIGN;
            else if (curr == EXP)
                curr = EXP_SIGN;
            else
                return false;
            break;

        default:
            return false;
            break;
        }
    }

    return curr == INT || curr == DECIMAL || curr == POINT || curr == EXP_NUM;
}