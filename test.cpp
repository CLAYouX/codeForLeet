#include<iostream>
#include<string>
#include<cstring>
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
#include<list>
using namespace std;

class base1
{
public:
    void print() {
        cout << "This is class base1." << endl;
    }
};

class base2
{
public:
    void print() {
        cout << "This is class base2." << endl;
    }
};

class derived: public base1, public base2
{

};

int main() {

    // 负数模
    int x = -16;
    cout << x%10 << endl;
    
    // x /= 10;
    // cout << x%10 << endl;

    // vector<int> vec = {1,1,2,3,4};

    // reverse(vec.begin(), vec.end());
    // for (auto &i : vec)
    //     cout << i << " ";

    char c = 'A' + 1;
    cout << c << endl;

    int a = 5, b = 15;

    cout << (a^b) << endl;

    cout << (4>>1) << endl;

    list<int> l;
    l.push_back(1);
    l.push_back(2);
    list<int>::iterator lit = l.begin();

    derived d;
    d.base1::print();

    string s = "Hello world.";
    const char *chr = s.data();
   
    s = "world";
    cout << chr << endl;

    return 0;
}