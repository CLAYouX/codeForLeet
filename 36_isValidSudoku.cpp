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

bool isValidSudoku(vector<vector<char>>& board);

int main() {

    vector<vector<char>> board = {{}};


    return 0;
}

bool isValidSudoku(vector<vector<char>>& board) {

    vector<vector<int>> rows(9, vector<int>(10, 0));
    vector<vector<int>> cols(9, vector<int>(10, 0));
    vector<vector<int>> boxes(9, vector<int>(10, 0));

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                int n = board[i][j] - '0';

                int box = (i / 3) * 3 + j / 3;
                if (rows[i][n] != 0 || cols[j][n] != 0 || boxes[box][n] != 0)
                    return false;

                rows[i][n] = 1;
                cols[j][n] = 1;
                boxes[box][n] = 1;
            }
        }
    }

    return true;
} 