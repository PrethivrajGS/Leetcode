class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        sort(nums.begin(), nums.end());  // Important: sort to handle duplicates
        backtrack(nums, result, current, used);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& used) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // Skip already used elements
            if (used[i]) continue;

            // Skip duplicates (only if the previous identical element wasn’t used)
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, result, current, used);
            current.pop_back();
            used[i] = false;
        }
    }
};