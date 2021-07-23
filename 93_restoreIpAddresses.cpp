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

vector<string> restoreIpAddresses(string s);

void IpAddress(vector<string> &ans, vector<int> &segments, string s, int start, int segment) {

    if (segment == 4 && start == s.size()) {
        string ip = "";
        for (int i = 0; i < segments.size()-1; ++i) {
            ip += to_string(segments[i]);
            ip.push_back('.');
        }
        ip += to_string(segments[segments.size()-1]);
        ans.push_back(ip);
        return;
    }

    if (segment >= 4)
        return;

    if (s[start] == '0') {
        segments.push_back(0);
        IpAddress(ans, segments, s, start+1, segment+1);
        segments.pop_back();
    }else
    {
        int num = 0;
        for (int i = 0; i < 3; ++i) {
            num = num*10 + s[start+i]-'0';
            if (num <= 255) {
                segments.push_back(num);
                IpAddress(ans, segments, s, start+i+1, segment+1);
                segments.pop_back();
            }
        }   
    }
}

int main() {

    string s = "101023";

    vector<string> ans = restoreIpAddresses(s);
    for (auto &ip : ans)
        cout << ip << endl;
        
    return 0;
}

vector<string> restoreIpAddresses(string s) {

    int n = s.size();
    if (n < 4)
        return {};

    vector<string> ans;
    vector<int> segments;
    IpAddress(ans, segments, s, 0, 0);

    return ans;
}