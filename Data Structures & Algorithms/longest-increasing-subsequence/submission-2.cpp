class Solution {
    //    private:
    //     vector<vector<int>> dp;
    //     int f(int ind, int prev_ind, vector<int>& nums) {
    //         if (ind == nums.size()) {
    //             return 0;
    //         }
    //         if (dp[ind][prev_ind + 1] != -1) {
    //             return dp[ind][prev_ind + 1];
    //         }

    //         int len = f(ind + 1, prev_ind, nums);

    //         if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
    //             len = max(len, 1 + f(ind + 1, ind, nums));
    //         }
    //         return dp[ind][prev_ind + 1] = len;
    //     }

   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};