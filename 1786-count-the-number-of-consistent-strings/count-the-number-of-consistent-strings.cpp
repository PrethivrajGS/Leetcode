

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowedChar(26, false);

        // Mark allowed characters
        for (char c : allowed) {
            allowedChar[c - 'a'] = true;
        }

        int count = 0;

        // Check each word
        for (string word : words) {
            bool isValid = true;
            for (char c : word) {
                if (!allowedChar[c - 'a']) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) count++;
        }

        return count;
    }
};
