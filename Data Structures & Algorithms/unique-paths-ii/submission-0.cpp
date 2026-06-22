class Solution {
   private:
    vector<vector<int>> dp;
    int f(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid) {
        if (i == m || j == n || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = f(i, j + 1, m, n, obstacleGrid) + f(i + 1, j, m, n, obstacleGrid);
    }

   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp.assign(m, vector<int>(n, -1));

        return f(0, 0, m, n, obstacleGrid);
    }
};
