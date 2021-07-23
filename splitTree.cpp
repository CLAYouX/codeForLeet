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

bool splitTreePart(int n, vector<vector<int>> &edges);

int main() {

    int n = 6;
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{4,5},{5,6}};

    cout << splitTreePart(n, edges) << endl;

    return 0;
}

bool splitTreePart(int n, vector<vector<int>> &edges) {

    if (n%3 != 0)
        return false;

    if (n == 3)
        return true;

    unordered_map<int, vector<int>> mp;

    for (auto &edge : edges) {
        mp[edge[0]].push_back(edge[1]);
    }

    int subTreeNum = n / 3;
    int cnt = 0, subTreeRoot; 

    for (auto &subTree : mp) {
        if (subTree.second.size() == subTreeNum-1) {
            ++cnt;
            subTreeRoot = subTree.first;
        }

        if (cnt == 2)
            return true;
    }

    if (cnt == 1) {
        for (auto &subTree : mp) {
            vector<int> subTreeNode = subTree.second;
            if ((find(subTreeNode.begin(), subTreeNode.end(), subTreeRoot) != subTreeNode.end()) && subTreeNode.size() == subTreeNum)
                return true;
        }
    }

    return false;
}