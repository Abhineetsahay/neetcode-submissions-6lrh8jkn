class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDeg(n + 1, 0), outDeg(n + 1, 0);

        for (auto& tru : trust) {
            outDeg[tru[0]]++;
            inDeg[tru[1]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (outDeg[i] == 0 && inDeg[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};