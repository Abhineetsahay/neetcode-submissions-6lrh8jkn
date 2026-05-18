class Solution {
   private:
    unordered_map<int, bool> dp;
    bool f(int i, string s, vector<string>& wordDict) {
        if (dp.find(i) != dp.end()) return dp[i];

        for (string& word : wordDict) {
            if (i + word.size() <= s.size() && s.substr(i, word.size()) == word) {
                if (f(i + word.size(), s, wordDict)) {
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }

   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dp[s.size()] = true;
        return f(0, s, wordDict);
    }
};
