class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> prev(m, vector<int>(n, 0));
        prev[startRow][startColumn] = 1;

        int result = 0;
        vector<int> dir = {0, 1, 0, -1, 0};

        for (int move = 1; move <= maxMove; move++) {
            vector<vector<int>> curr(m, vector<int>(n, 0));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (prev[i][j] > 0) {
                        for (int d = 0; d < 4; d++) {
                            int ni = i + dir[d];
                            int nj = j + dir[d + 1];

                            if (ni < 0 || nj < 0 || ni >= m || nj >= n) {
                                result = (result + prev[i][j]) % MOD;
                            } else {
                                curr[ni][nj] = (curr[ni][nj] + prev[i][j]) % MOD;
                            }
                        }
                    }
                }
            }
            prev = curr;
        }

        return result;
    }
};
