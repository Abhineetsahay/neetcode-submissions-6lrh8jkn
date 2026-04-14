class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> column[9];
        unordered_set<char> board_set[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if (board[i][j] == '.')
                    continue;

                char val = board[i][j];
                int boardInd= (i / 3) * 3 + j / 3;
                
                if (row[i].find(val) != row[i].end()) {
                    return false;
                }
                if (column[j].find(val) != column[j].end()) {
                    return false;
                }
                if (board_set[boardInd].find(val) !=
                    board_set[boardInd].end()) {
                    return false;
                }
                row[i].insert(val);
                column[j].insert(val);
                board_set[boardInd].insert(val);
            }
        }
        return true;
    }
};
