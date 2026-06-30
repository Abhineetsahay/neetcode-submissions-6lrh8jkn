class Solution {
   private:
    vector<vector<int>> ans;
    void f(int i, int n, int k, vector<int>& subset) {
        if (i > n) {
            if (subset.size() == k) {
                ans.push_back(subset);
            }
            return;
        }
        subset.push_back(i);
        f(i + 1, n, k, subset);
        subset.pop_back();
        f(i + 1, n, k, subset);
    }

   public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> subset;
        f(1, n, k, subset);
        return ans;
    }
};