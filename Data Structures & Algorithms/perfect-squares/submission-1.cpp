class Solution {
   private:
    vector<int> dp;
    // int f(int val) {
    //     if (val == 0) return 0;

    //     if (dp[val] != -1) return dp[val];

    //     int res = val;
    //     for (int i = 1; i * i <= val; i++) {
    //         res = min(res, 1 + f(val - i * i));
    //     }
    //     return dp[val] = res;
    // }

   public:
    int numSquares(int n) {
        dp.assign(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};