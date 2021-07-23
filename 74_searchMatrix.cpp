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

bool searchMatrix(vector<vector<int>>& matrix, int target);

bool binarySearch(vector<int> &rows, int n, int target) {

    int left = 0, right = n-1;
    while(left <= right) {
        int mid = left + (right-left)/2;
        if (rows[mid] == target)
            return true;
        else if (rows[mid] < target)
            left = mid+1;
        else
            right = mid-1;
    }

    return false;
}

int main() {

    vector<vector<int>> matrix = {{1,3,5,7},
                                  {10,11,16,20},
                                  {23,30,34,60}};
    
    int target = 13;

    cout << searchMatrix(matrix, target) << endl;

    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size(), n = matrix[0].size();

    int row = -1;
    for (int i = 0; i < m; ++i) {
        if (target >= matrix[i][0] && target <= matrix[i][n-1]) {
            row = i;
            break;
        }
    }

    if (row == -1)
        return false;

    return binarySearch(matrix[row], n, target);
}