class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> time(n, vector<int>(n, INT_MAX));
        time[0][0] = grid[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({grid[0][0], {0, 0}});

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            int currTime = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) {
                    int newTime = max(currTime, grid[nrow][ncol]);
                    if (newTime < time[nrow][ncol]) {
                        time[nrow][ncol] = newTime;
                        pq.push({newTime, {nrow, ncol}});
                    }
                }
            }

        }
        return time[n - 1][n - 1];
    }
};
