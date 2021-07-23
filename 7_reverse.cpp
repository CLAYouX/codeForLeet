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

int reverse(int x);

int main() {

    int x = -123;

    cout << reverse(x) << endl;

    return 0;
}

int reverse(int x) {

    int ans = 0;
    while(x) {
        int pop = x % 10;
        x /= 10;
        if ((ans > INT_MAX/10) || (ans == INT_MAX/10 && pop > 7))
            return 0;

        if ((ans < INT_MIN/10) || (ans == INT_MIN/10 && pop < -8))
            return 0;

        ans = ans*10 + pop;
    }

    return ans;
}