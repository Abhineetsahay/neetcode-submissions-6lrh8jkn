class Solution {
   private:
    vector<vector<int>> dp;

   public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.assign(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int fromTop = (i > 0) ? dp[i - 1][j] : INT_MAX;
                int fromLeft = (j > 0) ? dp[i][j - 1] : INT_MAX;

                dp[i][j] = grid[i][j] + min(fromTop, fromLeft);
            }
        }
        return dp[n - 1][m - 1];
    }
};