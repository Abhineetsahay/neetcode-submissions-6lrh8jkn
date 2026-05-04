class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;

        for (vector<int> point : points) {
            int x = point[0];
            int y = point[1];

            int dist = x * x + y * y;

            pq.push({dist, {x, y}});
        }

        while (pq.size() > k) {
            pq.pop();
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            ans.push_back({x, y});
            pq.pop();
        }
        return ans;
    }
};