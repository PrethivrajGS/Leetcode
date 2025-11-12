class Solution {
    vector<int> prefix;
    int total;
public:
    Solution(vector<int>& w) {
        prefix.resize(w.size());
        prefix[0] = w[0];
        for (int i = 1; i < w.size(); ++i)
            prefix[i] = prefix[i - 1] + w[i];
        total = prefix.back();
    }
    
    int pickIndex() {
        int r = rand() % total + 1; 
        int idx = lower_bound(prefix.begin(), prefix.end(), r) - prefix.begin();
        return idx;
    }
};
