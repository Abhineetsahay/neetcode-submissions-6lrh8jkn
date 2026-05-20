class Solution {
   private:
    vector<vector<int>> dp;
    int helper(int i, int j, string& s, string& t) {
        if (j < 0) return 1;
        if (i < 0) return 0;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == t[j]) {
            return dp[i][j] = helper(i - 1, j - 1, s, t) + helper(i - 1, j, s, t);
        } else {
            return dp[i][j] = helper(i - 1, j, s, t);
        }
    }

   public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.assign(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, s, t);
    }
};