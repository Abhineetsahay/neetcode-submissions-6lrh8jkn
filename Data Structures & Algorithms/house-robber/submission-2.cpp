class Solution {
private:
    vector<int>dp;
    int helper(vector<int>& nums){
        int n=nums.size();
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        return helper(nums);
    }
};
 