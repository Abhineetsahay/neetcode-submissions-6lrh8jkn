class Solution {
    int helper(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> temp1, temp2;

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != nums.size() - 1)
                temp2.push_back(nums[i]);
        }

        return max(helper(temp1), helper(temp2));
    }
};
