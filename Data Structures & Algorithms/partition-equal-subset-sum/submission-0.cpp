class Solution {
   private:
    vector<vector<int>> dp;
    bool f(int n, int target, vector<int>& nums) {
        if (n == 0 && target > 0) return false;
        if (target == 0) return true;

        if (dp[n][target] != -1) return dp[n][target];

        if (nums[n - 1] <= target) {
            return dp[n][target] = f(n - 1, target - nums[n - 1], nums) || f(n - 1, target, nums);
        } else {
            return dp[n][target] = f(n - 1, target, nums);
        }
    }

   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        dp.assign(n + 1, vector<int>(target + 1, -1));

        return f(n, target, nums);
    }
};
