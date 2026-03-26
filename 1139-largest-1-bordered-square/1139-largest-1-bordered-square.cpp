class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> right(n, vector<int>(m, 0));
        vector<vector<int>> down(n, vector<int>(m, 0));

        // Fill right and down arrays
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    right[i][j] = 1 + (j + 1 < m ? right[i][j + 1] : 0);
                    down[i][j] = 1 + (i + 1 < n ? down[i + 1][j] : 0);
                }
            }
        }

        int maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                for (int k = min(n - i, m - j); k > 0; k--) {

                    if (k <= maxSide) break;

                    if (right[i][j] >= k &&
                        down[i][j] >= k &&
                        right[i + k - 1][j] >= k &&
                        down[i][j + k - 1] >= k) {

                        maxSide = k;
                        break;
                    }
                }
            }
        }

        return maxSide * maxSide;
    }
};