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

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main() {

    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    for (auto &i : nums1)
        cout << i << " ";

    return 0;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    while(m && n) {
        if (nums1[m-1] > nums2[n-1]) {
            nums1[m+n-1] = nums1[m-1];
            --m;
        }else {
            nums1[m+n-1] = nums2[n-1];
            --n;
        }
    }

    while(n) {
        nums1[n-1] = nums2[n-1];
        --n;
    }
}