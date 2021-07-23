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

bool isPalindrome(int x);

int main() {

    int x = 12222221;

    cout << isPalindrome(x) << endl;

    return 0;
}

bool isPalindrome(int x) {

    if (x < 0)
        return false;

    int tmp = x, rev = 0;
    while(rev < tmp) {
        rev = rev*10 + tmp%10;
        tmp /= 10;
    }

    if (rev == tmp || tmp == rev/10)
        return true;

    return false;
}