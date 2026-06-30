class Solution {
   private:
    void f(int i, int n, vector<vector<int>>& ans, vector<int>& subset, vector<int>& nums) {
        if (i >= n) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        f(i + 1, n, ans, subset, nums);
        subset.pop_back();
        f(i + 1, n, ans, subset, nums);
    }

   public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        f(0, nums.size(), ans, subset, nums);

        int sum = 0;

        for (auto& it : ans) {
            int xorr=0;
            for (auto& val : it) {
                xorr ^= val;
            }
            sum+=xorr;
        }
        return sum;
    }
};