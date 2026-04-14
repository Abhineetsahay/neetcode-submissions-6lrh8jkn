class Solution {
private:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q,
             vector<vector<int>>& vis) {
        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vis[row][col] = true;
            for (int i = 0; i < 4; i++) {
                int dr = row + nrow[i];
                int dc = col + ncol[i];

                if (dr >= 0 && dr < heights.size() && dc >= 0 &&
                    dc < heights[0].size() && !vis[dr][dc] &&
                    heights[row][col] <= heights[dr][dc]) {
                    q.push({dr, dc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> atVis(n, vector<int>(m, 0));
        vector<vector<int>> paVis(n, vector<int>(m, 0));

        queue<pair<int, int>> atQ, paQ;

        for (int i = 0; i < n; i++) {
            paQ.push({i, 0});
            atQ.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            paQ.push({0, j});
            atQ.push({n - 1, j});
        }

        bfs(heights, atQ, atVis);
        bfs(heights, paQ, paVis);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (atVis[i][j] && paVis[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};