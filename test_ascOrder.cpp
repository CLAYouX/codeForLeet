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

bool canSwap(vector<int> &nums, vector<vector<int>> &pairs);

int main() {


    return 0;
}

bool isAscendOrder(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i-1] > nums[i])
            return false;
    }

    return true;
}

void dfs(vector<int> &nums, vector<vector<int>> &pair, int p) {

}

bool canSwap(vector<int> &nums, vector<vector<int>> &pairs) {
    bool ascendOrder = isAscendOrder(nums);

    if (ascendOrder)
        return true;

}

