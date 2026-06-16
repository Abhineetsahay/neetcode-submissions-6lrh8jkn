class Solution {
   private:
    vector<vector<int>> dp;
    int f(int i, int j, vector<vector<int>>& grid) {
        if (i == 0 && j == 0) {
            return grid[i][j];
        }
        if (i < 0 || j < 0) {
            return INT_MAX;
        }
        if (dp[i][j] != -1) return dp[i][j];

        int left = f(i - 1, j, grid);
        int up = f(i, j - 1, grid);
        return dp[i][j] = grid[i][j] + min(left, up);
    }

   public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.assign(n, vector<int>(m, -1));
        return f(n - 1, m - 1, grid);
    }
};