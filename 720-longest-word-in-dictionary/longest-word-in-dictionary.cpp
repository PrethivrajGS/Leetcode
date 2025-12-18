#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            if (a.length() == b.length())
                return a < b;
            return a.length() < b.length();
        });

        unordered_set<string> built;
        string ans = "";

        for (string &word : words) {
            if (word.length() == 1 || built.count(word.substr(0, word.length() - 1))) {
                built.insert(word);

                if (word.length() > ans.length()) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
