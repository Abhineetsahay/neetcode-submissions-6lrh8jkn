class TrieNode {
   public:
    TrieNode* children[26];

    bool isLeaf;

    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    bool containsKey(char ch) { return children[ch - 'a'] != nullptr; }

    void put(char ch, TrieNode* node) { children[ch - 'a'] = node; }

    TrieNode* get(char ch) { return children[ch - 'a']; }

    void setEnd() { isLeaf = true; }

    bool isEnd() { return isLeaf; }
};
class WordDictionary {
    TrieNode* root;

   private:
    bool searchHelper(string& word, int idx, TrieNode* node) {
        if (node == nullptr) return false;

        if (idx == word.size()) {
            return node->isEnd();
        }

        char ch = word[idx];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && searchHelper(word, idx + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        }

        if (!node->containsKey(ch)) return false;

        return searchHelper(word, idx + 1, node->get(ch));
    }

   public:
    WordDictionary() { root = new TrieNode(); }

void addWord(string word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (!node->containsKey(ch)) {
            node->put(ch, new TrieNode());
        }
        node = node->get(ch);
    }
    node->setEnd();
}

bool search(string word) { return searchHelper(word, 0, root); }
};
