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

int maximalRectangle(vector<vector<char>>& matrix);

int main() {

    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};


    cout << maximalRectangle(matrix) << endl;
    return 0;
}

int maximalRectangle(vector<vector<char>>& matrix) {

    int m = matrix.size(), n;
    if (m != 0)
        n = matrix[0].size();

    vector<vector<int>> heights(m, vector<int>(n));

    for (int i = 0; i < n; ++i)
        heights[0][i] = matrix[0][i]-'0';

    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != '0')
                heights[i][j] = heights[i-1][j] + 1;
        }
    }

    for (auto &v : heights) {
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
    }

    int maxArea = 0;
    for (int i = 0; i < m; ++i) {
        vector<int> left(n), right(n, n);
        stack<int> stk;
        
        for (int j = 0; j < n; ++j) {
            while(!stk.empty() && heights[i][stk.top()] >= heights[i][j]) {
                right[stk.top()] = j;
                stk.pop();
            }

            left[j] = stk.empty()? -1 : stk.top();
            stk.push(j);
        }

        for (int j = 0; j < n; ++j) {
            int area = (right[j]-left[j]-1)*heights[i][j];
            maxArea = max(area, maxArea);
        }
    }

    return maxArea;
}