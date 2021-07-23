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

int mySqrt(int x);

int main() {

    int x = 2147395599;

    cout << mySqrt(x) << endl;

    return 0;
}

int mySqrt(int x) {

    if (x == 0)
        return 0;

    int left = 1, right = x;
    int ans;
    while(left <= right) {

        long long mid = left + (right-left)/2;
        if (mid*mid == x || (mid*mid < x && (mid+1)*(mid+1) > x)) {
            ans = mid;
            break;
        } else if (mid*mid < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return ans;
}