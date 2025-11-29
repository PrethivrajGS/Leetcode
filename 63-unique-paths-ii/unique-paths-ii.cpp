class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If start is blocked
        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If obstacle, no paths here
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                // Skip the start cell
                if (i == 0 && j == 0) continue;

                long long ways = 0;

                if (i > 0) ways += dp[i - 1][j];   // from top
                if (j > 0) ways += dp[i][j - 1];   // from left

                dp[i][j] = ways;
            }
        }

        return dp[m - 1][n - 1];
    }
};
