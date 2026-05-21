class Solution {
   private:
    vector<vector<int>> dp;
    int f(int i, int j, string& s, string& p, int n, int m) {
        if (i >= n && j >= m) return true;
        if (j >= m) return false;

        if (dp[i][j] != -1) return dp[i][j];
        bool match = (i < n && (s[i] == p[j] || p[j] == '.'));
        if (j + 1 < m && p[j + 1] == '*') {
            return dp[i][j] = f(i, j + 2, s, p, n, m) || (match && f(i + 1, j, s, p, n, m));
        }

        if (match) {
            return dp[i][j] = f(i + 1, j + 1, s, p, n, m);
        }

        return dp[i][j] = false;
    }

   public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));

        return f(0, 0, s, p, n, m);
    }
};
