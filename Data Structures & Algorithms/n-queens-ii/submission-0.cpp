class Solution {
   private:
    void f(int col, int n, int& res, vector<int>& leftRow, vector<int>& upperDiagonal,
           vector<int>& lowerDiagonal) {
        if (col == n) {
            res++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                f(col + 1, n, res, leftRow, upperDiagonal, lowerDiagonal);

                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

   public:
    int totalNQueens(int n) {
        int res = 0;

        vector<int> leftRow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);

        f(0, n, res, leftRow, upperDiagonal, lowerDiagonal);

        return res;
    }
};