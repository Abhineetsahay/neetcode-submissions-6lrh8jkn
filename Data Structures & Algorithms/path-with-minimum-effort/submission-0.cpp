class Solution {
   public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), cols = heights[0].size();

        vector<vector<int>> dist(row, vector<int>(cols, INT_MAX));

        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == row - 1 && c == cols - 1) return diff;

            if (dist[r][c] < diff) continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nc < 0 || nr >= row || nc >= cols) {
                    continue;
                }

                int newDiff = max(diff, abs(heights[r][c] - heights[nr][nc]));

                if (newDiff < dist[nr][nc]) {
                    dist[nr][nc] = newDiff;
                    pq.push({newDiff, {nr, nc}});
                }
            }
        }
        return 0;
    }
};