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

int uniquePaths(int m, int n);

long long fac(int n) {
    if (n == 1)
        return 1;
    
    return (long long)n*fac(n-1);
}

int main() {

    int m = 1, n = 2;

    cout << uniquePaths(m,n) << endl;
    return 0;
}

int uniquePaths(int m, int n) {

    long long m_n_2 = fac(m+n-2);
    long long n_1 = n > 1? fac(n-1) : 1;
    long long m_1 = m > 1? fac(m-1) : 1;

    long long ans = m_n_2 / (m_1 * n_1);

    return ans;
}