#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dist(vector<int>& a, vector<int>& b) {
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, 
                     vector<int>& p3, vector<int>& p4) {
        
        vector<int> d;

        d.push_back(dist(p1, p2));
        d.push_back(dist(p1, p3));
        d.push_back(dist(p1, p4));
        d.push_back(dist(p2, p3));
        d.push_back(dist(p2, p4));
        d.push_back(dist(p3, p4));

        sort(d.begin(), d.end());

        // Check:
        // 4 equal sides and 2 equal diagonals
        return d[0] > 0 &&
               d[0] == d[1] &&
               d[1] == d[2] &&
               d[2] == d[3] &&
               d[4] == d[5];
    }
};