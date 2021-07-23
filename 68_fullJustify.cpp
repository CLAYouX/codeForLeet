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

vector<string> fullJustify(vector<string>& words, int maxWidth);

string fillWords(vector<string> &words, int begin, int end, int maxWidth, bool lastLine = false) {

    int wordCount = end - begin + 1;
    int spaceCount = maxWidth + 1 - wordCount;
    for (int i = begin; i <= end; ++i) {
        spaceCount -= words[i].size();
    }

    int spaceSuffix = 1;
    int spaceAvg = (wordCount == 1? 1 : spaceCount / (wordCount-1));
    int spaceExtra = (wordCount == 1? 0 : spaceCount % (wordCount-1));

    string ans;
    for (int i = begin; i < end; ++i) {
        ans += words[i];
        if (lastLine) {
            fill_n(back_inserter(ans), 1, ' ');
            continue;
        }
        fill_n(back_inserter(ans), spaceSuffix+spaceAvg+((i-begin) < spaceExtra), ' ');
    }
    ans += words[end];
    fill_n(back_inserter(ans), maxWidth-ans.size(), ' ');
    return ans;
}

int main() {

    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    vector<string> ans = fullJustify(words, maxWidth);
    for (auto &s : ans)
        cout << s << endl;

    return 0;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {

    int n = words.size();
    int begin = 0, wordsLength = 0;
    vector<string> ans;

    for (int i = 0; i < n; ++i) {
        wordsLength += (words[i].size()+1);
        if (i + 1 == n || wordsLength+words[i+1].size()+1 > maxWidth) {
            string word = fillWords(words, begin, i, maxWidth, (i+1 == n));
            ans.push_back(word);
            begin = i+1;
            wordsLength = 0;
        }
    }

    return ans;
}