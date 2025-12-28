#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string &a = words[i];
                string &b = words[j];
                
                if (b.size() >= a.size() &&
                    b.substr(0, a.size()) == a &&
                    b.substr(b.size() - a.size()) == a) {
                    count++;
                }
            }
        }
        return count;
    }
};
