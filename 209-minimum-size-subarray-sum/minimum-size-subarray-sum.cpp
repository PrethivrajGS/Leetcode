class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
    int min_len = INT_MAX;
    int start = 0, sum = 0;

    for (int end = 0; end < n; end++) {
        sum += nums[end];

        while (sum >= target) {
            min_len = min(min_len, end - start + 1);
            sum -= nums[start];
            start++;
        }
    }

    return (min_len == INT_MAX) ? 0 : min_len;
    }
};