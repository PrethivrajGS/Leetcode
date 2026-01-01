class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
     int n = s.size();
    vector<int> ans(n, n);
    
    int last = -n;
    // Left to right pass
    for (int i = 0; i < n; i++) {
        if (s[i] == c) last = i;
        ans[i] = i - last;
    }
    
    last = 2 * n;
    // Right to left pass
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) last = i;
        ans[i] = min(ans[i], last - i);
    }
    
    return ans;   
    }
};