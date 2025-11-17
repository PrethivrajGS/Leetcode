class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;

    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; 
            r--;
        }
        return true;
    }

    void backtrack(int start, const string &s) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(i + 1, s);
                path.pop_back();  // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(0, s);
        return result;
    }
};
