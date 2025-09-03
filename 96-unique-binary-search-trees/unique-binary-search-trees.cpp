class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int nodes = 2; nodes <= n; ++nodes) {
        long long total = 0;
        for (int root = 1; root <= nodes; ++root) {
            total += dp[root - 1] * dp[nodes - root];
        }
        dp[nodes] = total;
    }
    return (int)dp[n];
    }
};