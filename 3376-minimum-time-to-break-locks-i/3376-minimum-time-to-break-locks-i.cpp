class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        int N = 1 << n;

        vector<int> dp(N, INT_MAX);
        dp[0] = 0;

        for (int mask = 0; mask < N; mask++) {
            int used = __builtin_popcount(mask);
            int x = 1 + used * k;

            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    int newMask = mask | (1 << i);

                    int timeNeeded = (strength[i] + x - 1) / x;

                    dp[newMask] = min(dp[newMask],
                                      dp[mask] + timeNeeded);
                }
            }
        }

        return dp[N - 1];
    }
};