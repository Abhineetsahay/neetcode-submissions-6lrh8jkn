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
class PrefixTree {
   private:
    TrieNode* root;

   public:
    PrefixTree() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};
