class Solution {
    void f(int i, int n, int target, vector<vector<int>>& ans, vector<int>& subset,
           vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(subset);
            return;
        }
        if (i >= n) {
            return;
        }
        for (int j = i; j < n; j++) {
            if (j > i && candidates[j] == candidates[j - 1]) continue;

            if (candidates[j] > target) break;

            subset.push_back(candidates[j]);
            f(j + 1, n, target - candidates[j], ans, subset, candidates);
            subset.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        f(0, candidates.size(), target, ans, subset, candidates);
        return ans;
    }
};
