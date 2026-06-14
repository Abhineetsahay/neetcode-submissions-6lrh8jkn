class Solution {
   public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> charInd;
        for (int i = 0; i < order.size(); i++) {
            charInd[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i], word2 = words[i + 1];

            for (int j = 0; j < word1.size(); j++) {
                if (j == word2.size()) return false;
                if (word1[j] != word2[j]) {
                    if (charInd[word1[j]] > charInd[word2[j]]) {
                        return false;
                    }
                    break;
                }
            }
        }
        return true;
    }
};