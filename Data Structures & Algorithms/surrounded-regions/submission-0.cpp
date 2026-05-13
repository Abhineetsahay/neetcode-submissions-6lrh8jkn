class Solution {
   private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    void dfs(int i, int j, int m, int n, vector<vector<int>>& vis, vector<vector<char>>& board) {
        vis[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int r = i + dr[k];
            int c = j + dc[k];

            if (r >= 0 && r < m && c >= 0 && c < n && vis[r][c] == 0 && board[r][c] == 'O') {
                dfs(r, c, m, n, vis, board);
            }
        }
    }

   public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&
                    (vis[i][j] == 0 && board[i][j] == 'O')) {
                    dfs(i, j, m, n, vis, board);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
