class Solution {
   private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    vector<vector<int>> dp;

    int f(int r, int c, int m, int n, int prevVal, vector<vector<int>>& matrix) {
        if (r < 0 || r >= m | c < 0 || c >= n || matrix[r][c] <= prevVal) {
            return 0;
        }

        if (dp[r][c] != -1) return dp[r][c];
        int res = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            res = max(res, 1 + f(nr, nc, m, n, matrix[r][c], matrix));
        }
        return dp[r][c] = res;
    }

   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, f(i, j, m, n, INT_MIN, matrix));
            }
        }
        return ans;
    }
};
