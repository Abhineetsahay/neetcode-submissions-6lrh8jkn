class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int currMax = 0, globalMax = nums[0];
        int currMin = 0, globalMin = nums[0];
        int total = 0;
        for (int i = 0; i < n; i++) {
            currMax = max(currMax + nums[i], nums[i]);
            globalMax = max(globalMax, currMax);

            currMin = min(currMin + nums[i], nums[i]);
            globalMin = min(globalMin, currMin);

            total += nums[i];
        }

        int circularSum = total - globalMin;

        if (globalMin == total) {
            return globalMax;
        }

        return max(globalMax, circularSum);
    }
};