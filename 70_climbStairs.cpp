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

int climbStairs(int n);

vector<vector<long long>> multiply(vector<vector<long long>> m1, vector<vector<long long>> m2) {

    vector<vector<long long>> mm(2, vector<long long>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            mm[i][j] = m1[i][0]*m2[0][j] + m1[i][1]*m2[1][j];
        }
    }

    return mm;
}

vector<vector<long long>> maxtrixPow(vector<vector<long long>> m1, int n) {

    vector<vector<long long>> ans = {{1,0},{0,1}};
    vector<vector<long long>> base = m1;
    while(n > 0) {
        if (n & 0x1) {
            ans = multiply(ans, base);
        }

        base = multiply(base, base);

        n = n >> 1;
    }

    return ans;
}

int main() {

    int n = 5;

    cout << climbStairs(n) << endl;
    return 0;
}

int climbStairs(int n) {

    // vector<int> climb(n+1);
    // climb[0] = 1;
    // climb[1] = 1;

    // for (int i = 2; i <= n; ++i)
    //     climb[i] = climb[i-1] + climb[i-2];

    // return climb[n];

    vector<vector<long long>> res = {{1,1},{1,0}};
    vector<vector<long long>> ans = maxtrixPow(res, n);

    return ans[1][0] + ans[1][1];
}