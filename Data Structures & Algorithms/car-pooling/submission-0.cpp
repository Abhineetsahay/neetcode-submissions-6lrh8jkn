class Solution {
   public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int currPass = 0;

        for (auto& trip : trips) {
            int pass = trip[0], from = trip[1], to = trip[2];

            while (!pq.empty() && pq.top().first <= from) {
                currPass -= pq.top().second;
                pq.pop();
            }

            currPass += pass;
            if (currPass > capacity) return false;

            pq.push({to, pass});
        }
        return true;
    }
};