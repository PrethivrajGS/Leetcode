class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Sort by end coordinate
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int arrows = 1;
        long long last = points[0][1];  // position of current arrow

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > last) {
                arrows++;              // need a new arrow
                last = points[i][1];   // shoot at new end position
            }
        }

        return arrows;
    }
};
