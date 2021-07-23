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

int numTrees(int n);

int main() {

    int n = 4;

    cout << numTrees(n) << endl;

    return 0;
}

int numTrees(int n) {

    vector<int> f(n+1);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            f[i] += f[j]*f[i-1-j];
        }
    }

    return f[n];
}