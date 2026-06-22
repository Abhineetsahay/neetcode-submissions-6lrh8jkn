class Solution {
   private:
    vector<vector<int>> dp;
    // int f(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid) {
    //     if (i == m || j == n || obstacleGrid[i][j] == 1) {
    //         return 0;
    //     }
    //     if (i == m - 1 && j == n - 1) {
    //         return 1;
    //     }
    //     if (dp[i][j] != -1) return dp[i][j];

    //     return dp[i][j] = f(i, j + 1, m, n, obstacleGrid) + f(i + 1, j, m, n, obstacleGrid);
    // }

   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1) return 0;

        dp.assign(m + 1, vector<int>(n + 1, 0));

        dp[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
            }
        }
        return dp[0][0];
    }
};
