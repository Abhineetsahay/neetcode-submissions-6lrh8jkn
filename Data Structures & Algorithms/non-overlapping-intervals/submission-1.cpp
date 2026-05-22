class Solution {
   public:
    bool static comp(vector<int> i1, vector<int> i2) { return i1[1] < i2[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        int lastTime = intervals[0][1];
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (lastTime > intervals[i][0]) {
                res++;
            } else {
                lastTime = intervals[i][1];
            }
        }
        return res;
    }
};
