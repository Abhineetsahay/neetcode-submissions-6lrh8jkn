class Solution {
private:
    vector<int>dp;
    int helper(vector<int>& nums,int i){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(helper(nums,i+1),nums[i]+helper(nums,i+2));
    }
public:
    int rob(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        return helper(nums,0);
    }
};
 