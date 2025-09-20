class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int n = nums.size();
    long long total = (long long)n * (n + 1) / 2; 
    long long actual = 0;
    for (int num : nums) actual += num;
    return (int)(total - actual);
    }
};