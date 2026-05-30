class TrieNode {
   public:
    TrieNode* child[26];
    string word;

    TrieNode() {
        word = "";
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }
};

class Solution {
   public:
    vector<string> ans;
    int m, n;

    void insert(TrieNode* root, string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];

        if (ch == '#' || !node->child[ch - 'a']) return;

        node = node->child[ch - 'a'];

        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = ""; 
        }

        board[r][c] = '#';

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                dfs(board, nr, nc, node);
            }
        }

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string& word : words) insert(root, word);

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};