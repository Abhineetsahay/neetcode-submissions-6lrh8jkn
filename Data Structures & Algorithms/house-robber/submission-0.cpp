class Solution {
private:
    int helper(vector<int>& nums,int i){
        if(i>=nums.size()) return 0;

        return max(helper(nums,i+1),nums[i]+helper(nums,i+2));
    }
public:
    int rob(vector<int>& nums) {
        return helper(nums,0);
    }
};
 