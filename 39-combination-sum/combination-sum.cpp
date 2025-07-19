class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);

        dp[0] = {{}};

        for (int num : candidates) {
            for (int t = num; t <= target; ++t) {
                for (auto comb : dp[t - num]) {
                    comb.push_back(num);
                    dp[t].push_back(comb);
                }
            }
        }

        return dp[target];
    }
};
