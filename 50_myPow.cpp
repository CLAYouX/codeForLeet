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

double myPow(double x, int n);

int main() {

    double x = 1.0;
    int n = -2147483648;

    cout << myPow(x, n) << endl;

    return 0;
}

double myPow(double x, int n) {

    double ans = 1.0;
    double base = x;
    long long N = n >= 0? n : -(long long)n;
    while(N) {
        if (N & 0x1) {
            ans *= base;
        }

        base *= base;
        N = N >> 1;
    }

    return n >= 0 ?ans : (1/ans);
}