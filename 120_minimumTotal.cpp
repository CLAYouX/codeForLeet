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

int minimumTotal(vector<vector<int>>& triangle);

void dfs(vector<vector<int>>& triangle, int pathSum, int &minTotal, int row, int col) {
    if (row == triangle.size()) {
        if (pathSum < minTotal)
            minTotal = pathSum;

        return;
    }

    dfs(triangle, pathSum+triangle[row][col], minTotal, row+1, col);
    dfs(triangle, pathSum+triangle[row][col], minTotal, row+1, col+1);
}

int main() {

    vector<vector<int>> triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};

    cout << minimumTotal(triangle) << endl;

    return 0;
}

int minimumTotal(vector<vector<int>>& triangle) {

    int minTotal = INT_MAX;
    dfs(triangle, 0, minTotal, 0, 0);

    return minTotal;
}