class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int option1 = nums[n-1] * nums[n-2] * nums[n-3];  // top 3 largest
        int option2 = nums[0] * nums[1] * nums[n-1];      // 2 smallest + largest
        
        return max(option1, option2);
    }
};