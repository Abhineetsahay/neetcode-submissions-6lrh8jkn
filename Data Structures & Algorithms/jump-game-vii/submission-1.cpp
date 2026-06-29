class Solution {
   private:
    vector<int> dp;
    int f(int i, string& s, int& minJump, int& maxJump) {
        int n = s.size();
        if (i == n - 1) return true;

        if (dp[i] != -1) return dp[i];

        for (int j = i + minJump; j <= min(i + maxJump, n - 1); j++) {
            if (s[j] == '0' && f(j, s, minJump, maxJump)) {
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }

   public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        dp.assign(n, -1);

        return f(0, s, minJump, maxJump);
    }
};