class Solution {
   private:
    vector<int> dp;
    int f(int i, int n, string& s) {
        if (i == n) return 1;
        if (i > n || s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];
        int ways = f(i + 1, n, s);

        if (i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num <= 26) {
                ways += f(i + 2, n, s);
            }
        }
        return dp[i] = ways;
    }

   public:
    int numDecodings(string s) {
        int n = s.size();
        dp.assign(n, -1);
        return f(0, n, s);
    }
};
