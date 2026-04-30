
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        if (q.empty() || q.size() == n * n) return -1;

        int dist = -1;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            int size = q.size();
            dist++;

            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& d : dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};