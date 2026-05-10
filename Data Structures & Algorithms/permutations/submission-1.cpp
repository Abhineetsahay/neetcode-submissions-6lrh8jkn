class Solution {
   private:
    void f(vector<int>& res, vector<int>& nums, vector<bool>& pick, vector<vector<int>>& ans) {
        if (res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!pick[i]) {
                res.push_back(nums[i]);
                pick[i] = true;

                f(res, nums, pick, ans);
                res.pop_back();
                pick[i] = false;
            }
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> pick(nums.size(), false);
        f(res, nums, pick, ans);
        return ans;
    }
};
