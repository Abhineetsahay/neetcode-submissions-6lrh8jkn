class Solution {
   private:
    vector<vector<int>> dp;

    int f(int i, int j, vector<int>& nums) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int maxi = 0;
        for (int k = i; k <= j; k++) {
            int step = f(i, k - 1, nums) + f(k + 1, j, nums) + nums[i - 1] * nums[k] * nums[j + 1];
            maxi = max(maxi, step);
        }
        return dp[i][j] = maxi;
    }

   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return f(1, n, nums);
    }
};
