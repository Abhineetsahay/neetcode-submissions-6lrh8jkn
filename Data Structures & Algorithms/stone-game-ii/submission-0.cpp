class Solution {
   private:
    vector<vector<vector<int>>> dp;
    int f(int i, int alice, int m, vector<int>& piles) {
        if (i >= piles.size()) return 0;

        if (dp[i][alice][m] != -1) return dp[i][alice][m];
        int ans;

        if (alice) {
            ans = INT_MIN;
        } else {
            ans = INT_MAX;
        }
        int sum = 0;

        for (int x = 1; x <= 2 * m; x++) {
            if (i + x > piles.size()) break;

            sum += piles[i + x - 1];
            if (alice) {
                ans = max(ans, sum + f(i + x, 0, max(m, x), piles));
            } else {
                ans = min(ans, f(i + x, 1, max(m, x), piles));
            }
        }

        return dp[i][alice][m] = ans;
    }

   public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<vector<int>>(2, vector<int>(n + 1, -1)));
        return f(0, 1, 1, piles);
    }
};