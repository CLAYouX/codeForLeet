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

vector<int> getRow(int rowIndex);

int main() {

    vector<int> ans = getRow(3);
    for (auto &i : ans)
        cout << i << " ";

    return 0;
}

vector<int> getRow(int rowIndex) {

    vector<int> last = {1};
    
    vector<int> ans;
    for (int i = 1; i <= rowIndex; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i)
                ans.push_back(1);
            else
                ans.push_back(last[j-1]+last[j]);
        }

        last = ans;
        ans.clear();
    }

    return last;
}