class Solution {
   private:
    bool isValid(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
    bool dfs(int r, int c, int ind, string word, vector<vector<bool>>& visit,
             vector<vector<char>>& board) {
        if (board[r][c] != word[ind]) return false;

        visit[r][c] = true;

        if (ind == word.size() - 1) return true;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isValid(nr, nc, board.size(), board[0].size()) && !visit[nr][nc]) {
                if (dfs(nr, nc, ind + 1,word , visit, board)) {
                    return true;
                }
            }
        }
        visit[r][c] = false;
        return false;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visit(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, word, visit, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};
