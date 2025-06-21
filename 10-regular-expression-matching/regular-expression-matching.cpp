class Solution {
public:
    vector<vector<int>> memo;

    bool dp(int i, int j, const string &s, const string &p) {
        if (j == p.size()) return i == s.size();
        if (memo[i][j] != -1) return memo[i][j];

        bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            memo[i][j] = (dp(i, j + 2, s, p) || (firstMatch && dp(i + 1, j, s, p)));
        } else {
            memo[i][j] = (firstMatch && dp(i + 1, j + 1, s, p));
        }
        
        return memo[i][j];
    }

    bool isMatch(string s, string p) {
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dp(0, 0, s, p);
    }
};