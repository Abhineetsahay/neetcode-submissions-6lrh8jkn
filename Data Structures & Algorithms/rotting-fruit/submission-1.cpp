class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n));
        queue<pair<pair<int, int>, int>> q;
        int cntFresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        int ans = 0;
        int cnt = 0;

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;

            q.pop();

            ans = max(ans, time);

            for (int i = 0; i < 4; i++) {
                int r = row + drow[i];
                int c = col + dcol[i];

                if (r >= 0 && r < m && c >= 0 && c < n && vis[r][c] == 0 && grid[r][c] == 1) {
                    q.push({{r, c}, time + 1});
                    cnt++;
                    vis[r][c] = 2;
                }
            }
        }
        if (cnt != cntFresh) return -1;
        return ans;
    }
};
