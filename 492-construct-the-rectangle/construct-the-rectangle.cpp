class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = (int) sqrt(area);  // start from sqrt(area)
        while (area % W != 0) {
            W--; // find the nearest divisor
        }
        int L = area / W; // length
        return {L, W};
        
    }
};