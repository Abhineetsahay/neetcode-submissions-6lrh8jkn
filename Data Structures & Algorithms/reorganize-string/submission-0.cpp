class Solution {
   public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for (char& c : s) {
            freq[c - 'a']++;
        }

        string ans = "";
        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) pq.push({freq[i], 'a' + i});
        }

        while (!pq.empty()) {
            int cnt1 = pq.top().first;
            char ch1 = pq.top().second;
            pq.pop();

            if (ans.size() > 0 && ch1 == ans.back()) {
                if (pq.empty()) return "";
                int cnt2 = pq.top().first;
                int ch2 = pq.top().second;
                pq.pop();

                ans += ch2;
                cnt2--;
                if (cnt2 > 0) pq.push({cnt2, ch2});
                pq.push({cnt1, ch1});
            } else {
                ans += ch1;
                cnt1--;
                if (cnt1 > 0) pq.push({cnt1, ch1});
            }
        }

        if (ans.size() == s.size()) {
            return ans;
        }
        return "";
    }
};