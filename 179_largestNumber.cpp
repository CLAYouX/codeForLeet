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

string largestNumber(vector<int>& nums);

bool compare(const int &x, const int &y) {
    long sx = 10, sy = 10;
    while(sx <= x)
        sx *= 10;

    while(sy <= y)
        sy *= 10;

    return sy*x + y > sx*y + x;
}

int main() {

    vector<int> nums = {3,30,34,5,9};
    
    string ans = largestNumber(nums);
    cout << ans << endl;

    return 0;
}

string largestNumber(vector<int>& nums) {

    int n = nums.size();

    sort(nums.begin(), nums.end(), compare);
    string ans = "";
    for (auto i : nums)
        ans += to_string(i);

    return ans;
}