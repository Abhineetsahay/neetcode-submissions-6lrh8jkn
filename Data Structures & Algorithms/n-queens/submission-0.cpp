class Solution {
   private:
    void f(int col, int n, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow,
           vector<int>& upperDiagnol, vector<int>& lowerDiagnol) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagnol[row + col] == 0 &&
                upperDiagnol[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagnol[row + col] = 1;
                upperDiagnol[n - 1 + col - row] = 1;
                f(col + 1, n, board, ans, leftRow, upperDiagnol, lowerDiagnol);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagnol[row + col] = 0;
                upperDiagnol[n - 1 + col - row] = 0;
            }
        }
    }

   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> leftRow(n, 0), upperDiagnol(2 * n - 1, 0), lowerDiagnol(2 * n - 1, 0);

        f(0, n, board, ans, leftRow, upperDiagnol, lowerDiagnol);
        return ans;
    }
};