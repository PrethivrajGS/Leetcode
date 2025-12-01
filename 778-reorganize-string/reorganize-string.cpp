class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        // Quick impossibility check:
        for (auto &p : freq) {
            if (p.second > (n + 1) / 2) return "";
        }

        // Max-heap by remaining count
        priority_queue<pair<int,char>> pq;
        for (auto &p : freq) pq.push({p.second, p.first});

        string result;
        pair<int,char> prev = {0, '#'}; // previously used element that still may have remaining count

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            result += cur.second;
            cur.first--;

            // push back previous if it still has remaining count
            if (prev.first > 0) {
                pq.push(prev);
            }

            // current becomes previous for next iteration
            prev = cur;
        }

        // If there's leftover count, impossible
        if (prev.first > 0) return "";

        // final sanity check (length and adjacency)
        if (result.size() != s.size()) return "";
        for (int i = 1; i < (int)result.size(); ++i)
            if (result[i] == result[i-1]) return "";

        return result;
    }
};

