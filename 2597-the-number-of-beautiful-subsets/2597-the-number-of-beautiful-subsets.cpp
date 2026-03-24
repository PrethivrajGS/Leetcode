class Solution {
public:
    int count = 0;
    
    void backtrack(vector<int>& nums, int k, int index, unordered_map<int, int>& freq) {
        if (index == nums.size()) {
            count++;
            return;
        }
        
        backtrack(nums, k, index + 1, freq);
        
        int x = nums[index];
        
        if (freq[x - k] == 0 && freq[x + k] == 0) {
            freq[x]++;
            backtrack(nums, k, index + 1, freq);
            freq[x]--; 
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        backtrack(nums, k, 0, freq);
        return count - 1; 
    }
};