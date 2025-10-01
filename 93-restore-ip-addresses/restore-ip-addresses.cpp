

class Solution {
    vector<string> result;

    void backtrack(string &s, int start, int dots, string current) {
        
        if (dots == 3) {
            string last = s.substr(start);
            if (isValid(last)) {
                result.push_back(current + last);
            }
            return;
        }

        // Try segments of length 1 to 3
        for (int len = 1; len <= 3; len++) {
            if (start + len > s.size()) break;
            string part = s.substr(start, len);
            if (isValid(part)) {
                backtrack(s, start + len, dots + 1, current + part + ".");
            }
        }
    }

    bool isValid(string part) {
        if (part.empty() || part.size() > 3) return false;
        if (part.size() > 1 && part[0] == '0') return false; // no leading zero
        int val = stoi(part);
        return val >= 0 && val <= 255;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() < 4 || s.size() > 12) return {};
        backtrack(s, 0, 0, "");
        return result;
    }
};
