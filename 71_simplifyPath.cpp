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

string simplifyPath(string path);

int main() {

    string path = "/a//b////c/d//././/..";

    cout << simplifyPath(path) << endl;
    return 0;
}

string simplifyPath(string path) {

    vector<string> dirs;
    string dir = "";
    for (int i = 0; i < path.size(); ++i) {
        if (path[i] == '/') {
            if (dir == "..") {
                if (!dirs.empty())
                    dirs.pop_back();
            }else if (dir == "" || dir == ".");
            else {
                dirs.push_back(dir);
            }
            dir = "";
        }else
            dir.push_back(path[i]);
    }

    if (dir != "") {
        if (dir == "..") {
            if (!dirs.empty())
                dirs.pop_back();
        }else if (dir == ".");
        else {
            dirs.push_back(dir);
        }
    }

    if (!dirs.empty()) {
        string ans = "";
        for (auto &s : dirs) {
            ans.append("/");
            ans.append(s);
        }
        return ans;
    }else {
        return "/";
    }
}