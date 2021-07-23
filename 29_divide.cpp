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

int divide(int dividend, int divisor);

int mdiv(long a, long b) {  // a < 0 && b < 0
    if (a > b)
        return 0;

    int count = 1;
    int base = b;
    while((base-a+base) >= 0) {
        count *= 2;
        base *= 2;
    }

    return count + mdiv(a-base, b);
}

int main() {

    int dividend = 10, divisor = -3;

    cout << divide(dividend, divisor) << endl;
    return 0;
}

int divide(int dividend, int divisor) {

    if (dividend == 0)
        return 0;

    if (divisor == 1)
        return dividend;

    if (divisor == -1) {
        if (dividend == INT_MIN)
            return INT_MAX;
        else
            return -dividend;
    }

    int sign = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))? 1 : -1;

    dividend = -abs(dividend);
    divisor = -abs(divisor);
    int result = mdiv(dividend, divisor);

    return result*sign;
}