class Solution {
   private:
    vector<vector<int>> dp;
    // int f(int i, int amount, vector<int>& coins) {
    //     if (i == 0) {
    //         if (amount % coins[i] == 0)
    //             return 1;
    //         else
    //             return 0;
    //     }
    //     if (amount == 0) return 1;

    //     if (dp[i][amount] != -1) return dp[i][amount];

    //     if (coins[i] <= amount) {
    //         return dp[i][amount] = f(i, amount - coins[i], coins) + f(i - 1, amount, coins);
    //     }
    //     return dp[i][amount] = f(i - 1, amount, coins);
    // }

   public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        dp.assign(n, vector<int>(amount + 1, 0));
        // return f(n - 1, amount, coins);

        for (int i = 0; i <= amount; i++) {
            dp[0][i] = (i % coins[0] == 0) ? 1 : 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (coins[i] <= j) {
                    dp[i][j] = dp[i][j - coins[i]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][amount];
    }
};
