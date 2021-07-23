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

string multiply(string num1, string num2);

string add(string num1, string num2) {

    int m = num1.size(), n = num2.size();
    int carry = 0;
    string ans = "";
    while(m || n) {
        int add1 = m > 0 ? num1[m-1]-'0' : 0;
        int add2 = n > 0 ? num2[n-1]-'0' : 0;
        int sum = add1 + add2 + carry;
        ans.push_back((sum%10)+'0');
        carry = sum/10;

        if (m > 0)
            --m;
        
        if (n > 0)
            --n;
    }

    if (carry > 0)
        ans.push_back(carry+'0');
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    string num1 = "123", num2 = "456";
    // cout << add(num1, num2) << endl;

    cout << multiply(num1, num2) << endl;

    return 0;
}

string multiply(string num1, string num2) {

    if (num1 == "0" || num2 == "0")
        return "0";

    if (num1.size() < num2.size())
        swap(num1, num2);

    int m = num1.size(), n = num2.size();
    vector<string> multis;
    int zeroCnt = 0;
    for (int i = n-1; i >= 0; --i, ++zeroCnt) {
        int carry = 0;
        string multi = "";
        for (int j = m-1; j >= 0; --j) {
            int mul = (num1[j]-'0')*(num2[i]-'0')+carry;
            multi.push_back((mul%10)+'0');
            carry = mul/10;
        }
        if (carry > 0)
            multi.push_back(carry+'0');
        
        reverse(multi.begin(), multi.end());
        for (int k = 1; k <= zeroCnt; ++k)
            multi.push_back('0');

        multis.push_back(multi);
    }

    string ans = multis[0];
    for (int i= 1; i < multis.size(); ++i)
        ans = add(ans, multis[i]);

    return ans;
}