class Solution {
   private:
    void dfs(int row, int col, int& area, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        area += 1;
        vis[row][col] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < grid.size() && nr >= 0 && nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] == 1 && vis[nr][nc] == 0) {
                dfs(nr, nc, area, vis, grid);
            }
        }
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    int area = 0;
                    dfs(i, j, area, vis, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
