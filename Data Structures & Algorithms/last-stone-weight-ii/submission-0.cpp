class Solution {
   private:
    vector<vector<int>> dp;
    int f(int i, int sum, int totalSum, vector<int>& stones) {
        if (i == 0) {
            return abs(totalSum - 2 * sum);
        }
        if (dp[i][sum] != -1) return dp[i][sum];
        int take = f(i - 1, sum + stones[i - 1], totalSum, stones);
        int notTake = f(i - 1, sum, totalSum, stones);
        return dp[i][sum] = min(take, notTake);
    }

   public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        dp.assign(n + 1, vector<int>(totalSum + 1, -1));
        return f(n, 0, totalSum, stones);
    }
};