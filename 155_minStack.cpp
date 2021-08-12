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

class MinStack {

    stack<int> stk1, stk2;
public:
    /** initialize your data structure here. */
    MinStack() {
        stk1 = stack<int>();
        stk2 = stack<int>();
    }
    
    void push(int val) {
        if (stk1.empty() || val < stk2.top()) {
            stk1.push(val);
            stk2.push(val);
        }else {
            stk1.push(val);
            stk2.push(stk2.top());
        }
    }
    
    void pop() {
        stk1.pop();
        stk2.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
};