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

vector<vector<int>> generateMatrix(int n);

vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {

    int n = 4;

    vector<vector<int>> ans = generateMatrix(n);
    for (auto &v : ans) {
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> generateMatrix(int n) {

    vector<vector<int>> ans(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    int row = 0, col = 0;
    int index = 0;
    for (int i = 1; i <= n*n; ++i) {
        ans[row][col] = i;
        visited[row][col] = 1;
        int nextRow = row + directions[index][0], nextCol = col + directions[index][1];
        if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n || visited[nextRow][nextCol] == 1) {
            index = (index + 1) % 4;
        }

        row = row + directions[index][0];
        col = col + directions[index][1];
    }

    return ans;
}