class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        vector<int> cnt(26, 0);

        for (int i = 0; i < m; i++) {
            cnt[tasks[i] - 'A']++;
        }
        sort(cnt.begin(), cnt.end());
        int maxFreq = cnt[25];
        int idleSpot = (maxFreq - 1) * n;

        for (int i = 24; i >= 0; i--) {
            idleSpot -= min(maxFreq - 1, cnt[i]);
        }
        return max(0, idleSpot) + m;
    }
};
