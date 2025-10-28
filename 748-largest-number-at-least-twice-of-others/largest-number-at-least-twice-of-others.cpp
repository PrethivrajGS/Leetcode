class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxVal = INT_MIN, secondMax = INT_MIN;
        int index = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                secondMax = maxVal;
                maxVal = nums[i];
                index = i;
            } else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }

        return (maxVal >= 2 * secondMax) ? index : -1;
    }
};
