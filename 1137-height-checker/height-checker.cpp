class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;      // Make a copy
        sort(expected.begin(), expected.end());  // Sort it
        
        int count = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i])  // Count mismatches
                count++;
        }
        return count;
    }
};
