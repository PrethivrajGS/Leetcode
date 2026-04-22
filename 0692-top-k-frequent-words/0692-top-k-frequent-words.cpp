class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (auto& w : words) {
            freq[w]++;
        }

        vector<pair<string, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first < b.first; 
            return a.second > b.second;  
        });

\        vector<string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(vec[i].first);
        }

        return result;
    }
};