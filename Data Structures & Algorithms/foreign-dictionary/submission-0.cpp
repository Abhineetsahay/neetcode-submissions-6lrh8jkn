class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        vector<int> inDegree(26, 0), exists(26, 0);
        vector<vector<int>> adj(26);

        for (string word : words) {
            for (char ch : word) {
                exists[ch - 'a'] = 1;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            string first = words[i];
            string second = words[i + 1];

            int len = min(first.size(), second.size());

            bool fnd = false;

            for (int j = 0; j < len; j++) {
                if (first[j] != second[j]) {
                    adj[first[j] - 'a'].push_back(second[j] - 'a');
                    fnd = true;
                    inDegree[second[j] - 'a']++;
                    break;
                }
            }
            if (first.size() > second.size() && !fnd) return "";
        }

        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (exists[i] == 1 && inDegree[i] == 0) {
                q.push(i);
            }
        }

        string result = "";

        while (!q.empty()) {
            int node = q.front();

            q.pop();

            result += char(node + 'a');
            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (exists[i] == 1 && inDegree[i] != 0) {
                return "";
            }
        }
        return result;
    }
};
