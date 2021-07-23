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

void rotate(vector<vector<int>>& matrix);

int main() {

    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};

    rotate(matrix);

    for (auto &v : matrix) {
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

void rotate(vector<vector<int>>& matrix) {

    int n = matrix.size();

    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < (n+1)/2; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = tmp;
        }
    }
}