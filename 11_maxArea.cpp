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

int maxArea(vector<int>& height);

int main() {

    vector<int> height = {1,2,1};

    cout << maxArea(height) << endl;

    return 0;
}

int maxArea(vector<int>& height) {

    int n = height.size();

    int area = 0;
    int left = 0, right = n-1;
    while(left < right) {
        int tmpArea = min(height[left], height[right]) * (right-left);
        area = max(area, tmpArea);

        if (height[left] < height[right])
            ++left;
        else
            --right;
    }

    return area;
}