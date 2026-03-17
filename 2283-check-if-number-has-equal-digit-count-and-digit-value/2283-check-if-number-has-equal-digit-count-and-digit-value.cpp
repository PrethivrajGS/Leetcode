class Solution {
public:
    bool digitCount(string num) {
        vector<int> freq(10, 0);

        // Count frequency of digits
        for (char c : num) {
            freq[c - '0']++;
        }

        // Check condition
        for (int i = 0; i < num.size(); i++) {
            if (freq[i] != (num[i] - '0'))
                return false;
        }

        return true;
    }
};