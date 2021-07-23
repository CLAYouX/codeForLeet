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

vector<int> plusOne(vector<int>& digits);

int main() {

    vector<int> digits = {9,9};

    vector<int> sum = plusOne(digits);
    for (auto &i : sum)
        cout << i << " ";

    return 0;
}

vector<int> plusOne(vector<int>& digits) {

    int n = digits.size();

    vector<int> sum;
    int carry = 1;
    for (int i = n-1; i >= 0; --i) {
        int add = digits[i] + carry;
        sum.push_back(add%10);
        carry = add / 10;
    }

    if (carry > 0)
        sum.push_back(carry);

    reverse(sum.begin(), sum.end());

    return sum;
}