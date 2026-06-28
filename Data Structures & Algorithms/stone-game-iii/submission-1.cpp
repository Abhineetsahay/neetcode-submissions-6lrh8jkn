class Solution {
   private:
    vector<vector<int>> dp;
    int f(int i, int alice, vector<int>& stoneValue) {
        if (i >= stoneValue.size()) return 0;

        if (dp[i][alice] != -1) {
            return dp[i][alice];
        }
        int ans;
        if (alice)
            ans = INT_MIN;
        else
            ans = INT_MAX;

        int score = 0;
        for (int j = i; j < min(i + 3, (int)stoneValue.size()); j++) {
            if (alice) {
                score += stoneValue[j];
                ans = max(ans, score + f(j + 1, 0, stoneValue));
            } else {
                score -= stoneValue[j];
                ans = min(ans, score + f(j + 1, 1, stoneValue));
            }
        }
        return dp[i][alice] = ans;
    }

   public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, vector(2, -1));
        int ans = f(0, 1, stoneValue);

        if (ans == 0) return "Tie";

        if (ans > 0) return "Alice";
        return "Bob";
    }
};