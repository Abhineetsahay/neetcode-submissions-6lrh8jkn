class Solution {
   private:
    void f(int i, int n, int target, vector<vector<int>>& ans, vector<int>& subset,
           vector<int>& nums) {
        if (target == 0) {
            ans.push_back(subset);
            return;
        }
        if (i >= n) {
            return;
        }
        //take element
        if (nums[i] <= target) {
            subset.push_back(nums[i]);
            f(i, n, target - nums[i], ans, subset, nums);
            subset.pop_back();
        }
        //not take element
        f(i + 1, n, target, ans, subset, nums);
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        f(0, nums.size(), target, ans, subset, nums);
        return ans;
    }
};
