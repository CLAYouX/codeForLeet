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

vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};

bool exist(vector<vector<char>>& board, string word);

bool dfs(vector<vector<char>>& board, vector<vector<int>> &visited, string &word, int row, int col, int cur) {

    if (board[row][col] != word[cur]) {
        return false;
    }else if (cur == word.size()-1) {
        return true;
    }

    bool result = false;
    visited[row][col] = 1;
    for (int i = 0; i < 4; ++i) {
        int newRow = row + direction[i][0], newCol = col + direction[i][1];
        if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size() && visited[newRow][newCol] == 0) {
            bool flag = dfs(board, visited, word, newRow, newCol, cur+1);
            if (flag) {
                result = true;
                break;
            }
        }
    }

    visited[row][col] = 0;
    return result;
}

int main() {

    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','C','S'},
                                  {'A','D','E','E'}};

    string word = "ABCB";

    cout << exist(board, word) << endl;
    return 0;
}

bool exist(vector<vector<char>>& board, string word) {

    int m = board.size(), n = board[0].size();
    vector<vector<int>> visited(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            bool flag = dfs(board, visited, word, i, j, 0);
            if (flag)
                return true;
        }
    }

    return false;
}