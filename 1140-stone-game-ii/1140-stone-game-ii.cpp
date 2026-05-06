
class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int M, vector<int>& piles, vector<int>& suffix) {
        if (i >= n) return 0;

        if (dp[i][M] != -1) return dp[i][M];

        int res = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int opponent = solve(i + X, max(M, X), piles, suffix);
            res = max(res, suffix[i] - opponent);
        }

        return dp[i][M] = res;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.assign(n, vector<int>(n + 1, -1));

        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        return solve(0, 1, piles, suffix);
    }
};