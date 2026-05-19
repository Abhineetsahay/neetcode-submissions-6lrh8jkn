class Solution {
   private:
    vector<vector<int>> dp;
    int f(int i, int j, string& text1, string& text2) {
        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        if (text1[i - 1] == text2[j - 1]) {
            return dp[i][j] = 1 + f(i - 1, j - 1, text1, text2);
        }
        return dp[i][j] = max(f(i - 1, j, text1, text2), f(i, j - 1, text1, text2));
    }

   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return f(n, m, text1, text2);
    }
};
