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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main() {

    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int m = nums1.size(), n = nums2.size();

    vector<int> nums(m+n);
    int p1 = 0, p2 = 0;

    while(p1 < m && p2 < n) {
        if (nums1[p1] <= nums2[p2]) {
            nums[p1+p2] = nums1[p1];
            ++p1;
        }else {
            nums[p1+p2] = nums2[p2];
            ++p2;
        }
    }

    while(p1 < m) {
        nums[p1+p2] = nums1[p1];
        ++p1;
    }

    while(p2 < n) {
        nums[p1+p2] = nums2[p2];
        ++p2;
    }

    double median;
    if ((m+n)%2)
        median = nums[(m+n)/2];
    else
        median = (nums[(m+n)/2] + nums[(m+n)/2 - 1]) / 2.0;

    return median;
}