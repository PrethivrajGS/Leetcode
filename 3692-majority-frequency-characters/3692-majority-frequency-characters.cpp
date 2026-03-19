
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        unordered_map<int, vector<char>> groups;
        for (auto &p : freq) {
            groups[p.second].push_back(p.first);
        }

        int maxSize = 0;
        int bestFreq = 0;

        for (auto &g : groups) {
            int k = g.first;
            int size = g.second.size();

            if (size > maxSize || (size == maxSize && k > bestFreq)) {
                maxSize = size;
                bestFreq = k;
            }
        }

        string result = "";
        for (char c : groups[bestFreq]) {
            result += c;
        }

        return result;
    }
};