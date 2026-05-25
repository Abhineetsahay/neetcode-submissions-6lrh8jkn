class Solution {
   public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        vector<int> ans;
        int size = 0;
        int end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, mp[s[i]]);
            size++;
            if (i == end) {
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
};
