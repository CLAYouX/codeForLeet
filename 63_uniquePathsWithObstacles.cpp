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

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

int main() {

    vector<vector<int>> obstacleGrid = {{0,0,0},
                                        {0,1,0},
                                        {0,0,0}};

    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    vector<vector<int>> paths(m, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        if (obstacleGrid[0][i] == 1)
            break;

        paths[0][i] = 1;
    }

    for (int i = 0; i < m; ++i) {
        if (obstacleGrid[i][0] == 1)
            break;

        paths[i][0] = 1;
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 1)
                paths[i][j] = 0;
            else
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
        }
    }

    return paths[m-1][n-1];
}