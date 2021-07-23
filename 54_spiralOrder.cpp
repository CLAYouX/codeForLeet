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

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main() {

    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};

    vector<int> ans = spiralOrder(matrix);
    for (auto &i : ans)
        cout << i << " ";

    return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    int top = 0, bottom = m-1, left = 0, right = n-1;
    vector<int> ans;

    while(left <= right && top <= bottom) {

        for (int i = left; i <= right; ++i) {
            ans.push_back(matrix[top][i]);
        }

        for (int i = top+1; i < bottom; ++i) {
            ans.push_back(matrix[i][right]);
        }

        if (left < right && top < bottom) {
            for (int i = right; i >= left; --i) {
                ans.push_back(matrix[bottom][i]);
            }

            for (int i = bottom-1; i > top; --i) {
                ans.push_back(matrix[i][left]);
            }
        }     

        ++top;
        ++left;
        --bottom;
        --right;
    }

    return ans;
}