class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap;
        for (char c : t) {
            tmap[c]++;
        }

        int left = 0, right = 0;
        int minLen = INT_MAX, sInd = -1;
        int cnt = 0, tsize = tmap.size();

        unordered_map<char, int> smap;

        while (right < s.size()) {
            char c = s[right];
            smap[c]++;

            if (tmap.count(c) && tmap[c] == smap[c]) {
                cnt++;
            }
            while (cnt == tsize) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    sInd = left;
                }

                char ch = s[left];
                smap[ch]--;
                if (tmap.count(ch) && smap[ch] < tmap[ch]) {
                    cnt--;
                }
                left++;
            }
            right++;
        }
        return sInd == -1 ? "" : s.substr(sInd, minLen);
    }
};
