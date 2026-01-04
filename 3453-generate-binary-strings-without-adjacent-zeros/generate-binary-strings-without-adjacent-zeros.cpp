

class Solution {
public:
    vector<string> result;

    void backtrack(string &current, int n) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }

        // Always can add '1'
        current.push_back('1');
        backtrack(current, n);
        current.pop_back();

        // Add '0' only if last char is not '0'
        if (current.empty() || current.back() == '1') {
            current.push_back('0');
            backtrack(current, n);
            current.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        string current = "";
        backtrack(current, n);
        return result;
    }
};
