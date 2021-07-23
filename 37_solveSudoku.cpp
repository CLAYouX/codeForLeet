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

void solveSudoku(vector<vector<char>>& board);

int rows[9][10] = {0};
int cols[9][10] = {0};
int boxes[9][10] = {0};
bool solved = false;

void dfs(vector<vector<char>>& board, int row, int col) {
    if (row == 9) {
        solved = true;
        return;
    }

    int box = (row / 3) * 3 + col / 3;
    if (board[row][col] == '.') {
        for (int i = 1; i <= 9; ++i) {
            if (rows[row][i] == 0 && cols[col][i] == 0 && boxes[box][i] == 0) {
                rows[row][i] = 1;
                cols[col][i] = 1;
                boxes[box][i] = 1;

                board[row][col] = i + '0';
                if (col == 8)
                    dfs(board, row+1, 0);
                else
                    dfs(board, row, col+1);

                if (solved)
                    return;

                board[row][col] = '.';
                rows[row][i] = 0;
                cols[col][i] = 0;
                boxes[box][i] = 0;
            }
        }
    }else {
        if (col == 8)
            dfs(board, row+1, 0);
        else
            dfs(board, row, col+1);
    }
}

int main() {

    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};

    solveSudoku(board);
    for (auto &v : board) {
        for (auto &c : v)
            cout << c << " ";
        cout << endl;
    }


    return 0;
}

void solveSudoku(vector<vector<char>>& board) {

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                int n = board[i][j] - '0';

                int box = (i / 3) * 3 + j / 3;
                rows[i][n] = 1;
                cols[j][n] = 1;
                boxes[box][n] = 1;
            }
        }
    }
    
    dfs(board, 0, 0);
}