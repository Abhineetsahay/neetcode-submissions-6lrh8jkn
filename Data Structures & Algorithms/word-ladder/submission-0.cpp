class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        unordered_set<string> words(wordList.begin(), wordList.end());
        words.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if (word == endWord) {
                return level;
            }

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char j = 'a'; j <= 'z'; j++) {
                    word[i] = j;
                    if (words.find(word) != words.end()) {
                        q.push({word, level + 1});
                        words.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
