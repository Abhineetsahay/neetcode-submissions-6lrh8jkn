class Solution {
   private:
    void f(int i, int n, vector<vector<int>>& ans, vector<int>& subset, vector<int>& nums) {
        ans.push_back(subset);
        for (int j = i; j < n; j++) {
            if (j > i && nums[j] == nums[j - 1]) continue;

            subset.push_back(nums[j]);
            f(j + 1, n, ans, subset, nums);
            subset.pop_back();
        }
    }

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;

        f(0, n, ans, subset, nums);
        return ans;
    }
};
