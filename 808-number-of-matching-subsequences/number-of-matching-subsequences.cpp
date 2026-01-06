
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        int count = 0;

        // Check each word
        for (string &word : words) {
            int prevIndex = -1;
            bool isSubsequence = true;

            for (char c : word) {
                auto &indices = pos[c - 'a'];

                // Binary search to find index > prevIndex
                auto it = upper_bound(indices.begin(), indices.end(), prevIndex);
                if (it == indices.end()) {
                    isSubsequence = false;
                    break;
                }
                prevIndex = *it;
            }

            if (isSubsequence) count++;
        }

        return count;
    }
};
