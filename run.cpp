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

int main() {

    int N, T1, T2, T3, T4;

    cin >> N >> T1 >> T2 >> T3 >> T4;

    vector<int> height(N);
    for (int i = 0; i < N; ++i) {
        cin >> height[i];
    }

    vector<int> time(N), mirror(N);
    time[N-1] = 0;
    mirror[N-1] = 0;

    for (int i = N-2; i > 0; --i) {
        if (height[i+1] > height[i]+1) {
            time[i] = T4+T3+mirror[i+1];
            mirror[i] = T3+mirror[i+1];
        }else if (height[i+1]+1 < height[i]) {
            time[i] = T3 + time[i+1];
            mirror[i] = T4+T3+time[i+1];
        }else if (height[i] == height[i+1] - 1){
            time[i] = min(T2+time[i+1], T4+T3+mirror[i+1]);
            mirror[i] = min(T3+mirror[i+1], T4+T2+time[i+1]);
        }else if (height[i] == height[i+1] + 1) {
            time[i] = min(T3+time[i+1], T4+T2+mirror[i+1]);
            mirror[i] = min(T2+mirror[i+1], T4+T3+mirror[i+1]);
        }else {
            time[i] = min(T1+time[i+1], T4+T1+mirror[i+1]);
            mirror[i] = min(T1+mirror[i+1], T4+T1+time[i+1]);
        }
    }

    int minTime = 0;
    if (height[0] > height[1]) {
        if (height[0] > height[1]+1)
            minTime = T3 + time[1];
        else
            minTime = min(T3+time[1], T4+T2+mirror[1]);
    }else if (height[0] < height[1]) {
        if (height[0]+1 < height[1])
            minTime = T4+T3+mirror[1];
        else
            minTime = min(T2+time[1], T4+T3+mirror[1]);
    }else {
        minTime = min(T1+time[1], T4+T1+mirror[1]);
    }
    
    cout << minTime << endl;

    return 0;
}