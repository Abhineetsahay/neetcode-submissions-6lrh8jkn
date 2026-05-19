class Solution {
   private:
    vector<vector<int>> dp;
    int f(int i, bool buy, vector<int>& prices) {
        if (i >= prices.size()) {
            return 0;
        }
        if (dp[i][buy] != -1) return dp[i][buy];
        
        if (buy) {
            return dp[i][buy] = max(-prices[i] + f(i + 1, 0, prices), f(i + 1, 1, prices));
        } else {
            return dp[i][buy] = max(prices[i] + f(i + 2, 1, prices), f(i + 1, 0, prices));
        }
    }

   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return f(0, true, prices);
    }
};
