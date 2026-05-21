class Solution {
   private:
    vector<vector<int>> dp;
    bool f(int i, int j, string s1, string s2, string s3) {
        if (i == s1.size() && j == s2.size()) return true;

        if (dp[i][j] != -1) return dp[i][j];

        int k = i + j;
        bool takeS1 = false;
        bool takeS2 = false;

        if (i < s1.size() && s1[i] == s3[k]) {
            takeS1 = f(i + 1, j, s1, s2, s3);
        }

        if (j < s2.size() && s2[j] == s3[k]) {
            takeS2 = f(i, j + 1, s1, s2, s3);
        }

        return dp[i][j] = (takeS1 || takeS2);
    }

   public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        if (n + m != s3.size()) return false;

        dp.assign(n + 1, vector<int>(n + 1, -1));

        return f(0, 0, s1, s2, s3);
    }
};
