class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        // Check if reshape is possible
        if (m * n != r * c)
            return mat;

        vector<vector<int>> res(r, vector<int>(c));
        int idx = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[idx / c][idx % c] = mat[i][j];
                idx++;
            }
        }
        return res;
    }
};