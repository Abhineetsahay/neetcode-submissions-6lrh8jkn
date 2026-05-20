class Solution {
   private:
    vector<vector<int>> dp;
    int f(int i, int amount, vector<int>& coins) {
        if (i == 0) {
            if (amount % coins[i] == 0)
                return 1;
            else
                return 0;
        }
        if (amount == 0) return 1;

        if (dp[i][amount] != -1) return dp[i][amount];

        if (coins[i] <= amount) {
            return dp[i][amount] = f(i, amount - coins[i], coins) + f(i - 1, amount, coins);
        }
        return dp[i][amount] = f(i - 1, amount, coins);
    }

   public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        dp.assign(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins);
    }
};
