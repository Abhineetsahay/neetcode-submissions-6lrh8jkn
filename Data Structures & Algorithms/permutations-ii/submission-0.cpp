class Solution {
   public:
    vector<vector<int>> res;
    vector<bool> visit;

    void f(vector<int>& nums, vector<int>& perm) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i-1])) continue;

            visit[i]=true;
            perm.push_back(nums[i]);
            f(nums,perm);
            visit[i]=false;
            perm.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        visit.assign(n, false);

        sort(nums.begin(), nums.end());
        vector<int>perm;

        f(nums,perm);
        return res;
    }
};