class Solution {
public:
    vector<int> grayCode(int n) {
         vector<int> res;
    int m = 1 << n;               
    res.reserve(m);
    for (int i = 0; i < m; ++i) {
        res.push_back(i ^ (i >> 1));
    }
    return res;
    }
};