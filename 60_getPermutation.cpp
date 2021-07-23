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

string getPermutation(int n, int k);

int fac(int n) {

    if (n == 1)
        return 1;
    
    return n*fac(n-1);
}

int main() {

    int n = 3, k = 2;

    cout << getPermutation(n, k) << endl;

    return 0;
}

string getPermutation(int n, int k) {

    string ans = "";

    vector<int> factorial(n);
    factorial[0] = 1;
    for (int i = 1; i < n; ++i) {
        factorial[i] = factorial[i - 1] * i;
    }

    --k;
    vector<int> used(n+1, 1);
    while(n > 1) {
        int p = k / factorial[n-1] + 1;
        for (int i = 1; i <= factorial.size(); ++i) {
            p -= used[i];
            if (p == 0) {
                ans.push_back(i+'0');
                used[i] = 0;
                break;
            }
        }
        k = k % factorial[n-1];
        cout << "k = " << k << endl;
        --n;
    }

    for (int i = 1; i < used.size(); ++i) {
        if (used[i] == 1) {
            ans.push_back(i+'0');
            break;
        }
    }

    return ans;
}