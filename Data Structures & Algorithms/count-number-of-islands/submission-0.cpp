class Solution {
   private:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= grid.size() || nr < 0 || nc >= grid[0].size() || nc < 0 || vis[nr][nc])
                continue;

            if (grid[nr][nc] == '1') {
                dfs(nr, nc, grid, vis);
            }
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
