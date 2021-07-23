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

string addBinary(string a, string b);

int main() {

    string a = "1010", b = "1011";

    cout << addBinary(a, b) << endl;

    return 0;
}

string addBinary(string a, string b) {

    int m = a.size(), n = b.size();

    string ans = "";
    int carry = 0;
    
    while(m > 0 || n > 0) {
        int a1 = (m > 0) ? (a[m-1]-'0') : 0;
        int a2 = (n > 0) ? (b[n-1]-'0') : 0;
        int sum = a1 + a2 + carry;
        ans.push_back(sum%2+'0');
        carry = sum / 2;

        --m;
        --n;
    }

    if (carry > 0)
        ans.push_back(carry+'0');

    reverse(ans.begin(), ans.end());

    return ans;
}