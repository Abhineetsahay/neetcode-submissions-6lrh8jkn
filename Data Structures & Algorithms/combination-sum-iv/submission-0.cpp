class Solution {
    vector<int> dp;
    int f(int target, vector<int>& nums) {
        if (target == 0) return 1;
        if (target < 0) return 0;

        if (dp[target] != -1) return dp[target];
        int ans = 0;

        for (int num : nums) {
            ans += f(target - num, nums);
        }

        return dp[target] = ans;
    }

   public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target + 1, -1);
        return f(target, nums);
    }
};