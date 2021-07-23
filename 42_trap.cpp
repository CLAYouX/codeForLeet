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

int trap(vector<int>& height);

int main() {

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trap(height) << endl;
    return 0;
}

int trap(vector<int>& height) {

    int n = height.size();
    if (n == 0)
        return 0;

    vector<int> leftmax(n);
    leftmax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftmax[i] = max(height[i], leftmax[i-1]);
    }

    vector<int> rightmax(n);
    rightmax[n-1] = height[n-1];
    for (int i = n-2; i >= 0; --i) {
        rightmax[i] = max(height[i], rightmax[i+1]);
    }

    int sum = 0;
    for (int i = 0; i <n; ++i) {
        sum += min(leftmax[i], rightmax[i]) - height[i];
    }

    return sum;
}