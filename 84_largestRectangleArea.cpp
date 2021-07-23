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

int largestRectangleArea(vector<int>& heights);

int main() {

    vector<int> heights = {1,1,1,1,1,1};

    cout << largestRectangleArea(heights) << endl;
    return 0;
}

int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();
    vector<int> left(n), right(n);

    stack<int> stk;

    for (int i = 0; i < n; ++i) {
        while(!stk.empty() && heights[stk.top()] >= heights[i])
            stk.pop();

        left[i] = stk.empty()? -1 : stk.top();
        stk.push(i);
    }

    stk = stack<int>();
    for (int i = n-1; i >= 0; --i) {
        while(!stk.empty() && heights[stk.top()] >= heights[i])
            stk.pop();

        right[i] = stk.empty()? n : stk.top();
        stk.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
        maxArea = max(maxArea, (right[i]-left[i]-1)*heights[i]);
    }
    

    return maxArea;
}