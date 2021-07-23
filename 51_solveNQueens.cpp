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

vector<vector<string>> solveNQueens(int n);

unordered_set<int> columns;
unordered_set<int> diags1, diags2;

vector<string> generateBoard(vector<int> queens, int n) {

    vector<string> board;
    for (int i = 0; i < n; ++i) {
        string row = string(n, '.');
        row[queens[i]] = 'Q';
        board.push_back(row);
    }

    return board;
}

void dfs(vector<vector<string>> &ans, vector<int>& queens, int n, int row) {
    if (row == n) {
        vector<string> board = generateBoard(queens, n);
        ans.push_back(board);
        return;
    }else {
        for (int i = 0; i < n; ++i) {
            if (columns.find(i) != columns.end()) {
                continue;
            }

            int diag1 = row - i;
            if (diags1.find(diag1) != diags1.end()) {
                continue;
            }

            int diag2 = row + i;
            if (diags2.find(diag2) != diags2.end()) {
                continue;
            }

            queens.push_back(i);
            columns.insert(i);
            diags1.insert(diag1);
            diags2.insert(diag2);
            dfs(ans, queens, n, row+1);
            diags2.erase(diag2);
            diags1.erase(diag1);
            columns.erase(i);
            queens.pop_back();
        }
    }

    
}

int main() {

    int n = 4;

    vector<vector<string>> ans = solveNQueens(n);
    for (auto &v: ans) {
        for (auto &s : v)
            cout << s << endl;
        cout << endl;
    }

    return 0;
}

vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> ans;
    vector<int> queens;

    dfs(ans, queens, n, 0);

    return ans;
}