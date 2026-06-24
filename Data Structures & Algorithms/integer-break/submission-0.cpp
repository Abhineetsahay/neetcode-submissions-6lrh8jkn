class Solution {
   private:
    vector<int> dp;
    int f(int val, int oriVal) {
        if (val == 1) return val;

        if (dp[val] != -1) return dp[val];
        
        int res = (val == oriVal) ? 0 : val;
        for (int i = 1; i < val; i++) {
            int newVal = f(i, oriVal) * f(val - i, oriVal);

            res = max(res, newVal);
        }
        return dp[val] = res;
    }

   public:
    int integerBreak(int n) {
        dp.assign(n + 1, -1);
        dp[1] = 1;
        return f(n, n);
    }
};