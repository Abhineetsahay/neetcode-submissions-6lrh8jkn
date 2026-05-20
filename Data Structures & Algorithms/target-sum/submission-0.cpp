class Solution {
   private:
    vector<vector<int>> dp;

    int countWays(int n, int target, vector<int>& nums) {
        if (n == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == 0 || nums[0] == target) return 1;
            return 0;
        }

        if (dp[n][target] != -1) return dp[n][target];

        int notTake = countWays(n - 1, target, nums);
        int take = 0;

        if (target >= nums[n]) {
            take = countWays(n - 1, target - nums[n], nums);
        }
        return dp[n][target] = take + notTake;
    }

   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if ((target + sum) % 2 != 0 || abs(target) > sum) {
            return 0;
        }
        int s1 = (target + sum) / 2;

        dp.assign(n, vector<int>(s1 + 1, -1));
        return countWays(n - 1, s1, nums);
    }
};
