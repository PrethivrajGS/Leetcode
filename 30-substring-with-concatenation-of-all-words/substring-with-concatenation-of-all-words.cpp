class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> need;
        for (auto &w : words) need[w]++;

        // Try each offset
        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> window;
            int left = i, count = 0;

            for (int right = i; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (need.count(word)) {
                    window[word]++;
                    count++;

                    // Too many of this word → shrink
                    while (window[word] > need[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Valid concatenation found
                    if (count == wordCount) {
                        result.push_back(left);

                        // Move window forward
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    // Reset window
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};
