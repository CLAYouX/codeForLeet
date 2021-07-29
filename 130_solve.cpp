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

void solve(vector<vector<char>>& board);

void dfs(vector<vector<char>> &board, int m, int n, int x, int y) {

    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
        return;

    board[x][y] = 'A';
    dfs(board, m, n, x, y-1);
    dfs(board, m, n, x-1, y);
    dfs(board, m, n, x, y+1);
    dfs(board, m, n, x+1, y);
}

int main() {

    vector<vector<char>> board = {{'X','X','X','X'},
                                  {'X','O','O','X'},
                                  {'X','X','O','X'},
                                  {'X','O','X','X'}};

    solve(board);

    for(auto &v : board) {
        for (auto c : v)
            cout << c << " ";
        cout << endl;
    }

    return 0;
}

void solve(vector<vector<char>>& board) {

    int m = board.size(), n = board[0].size();

    for (int i = 0; i < n; ++i) {
        dfs(board, m, n, 0, i);
        dfs(board, m, n, m-1, i);
    }

    for (int i = 1; i < m-1; ++i) {
        dfs(board, m, n, i, 0);
        dfs(board, m, n, i, n-1);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'A') {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}