class Solution {
   public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                          {'C', 100}, {'D', 500}, {'M', 1000}};

        int ans = 0;
        int i = s.size() - 1;
        while (i > 0) {
            char firstChar = s[i];
            char secondChar = s[i - 1];

            if (firstChar == 'V' || firstChar == 'X') {
                if (secondChar == 'I') {
                    ans += (firstChar == 'V' ? 4 : 9);
                    i -= 2;
                } else {
                    ans += roman[firstChar];
                    i--;
                }
            } else if (firstChar == 'L' || firstChar == 'C') {
                if (secondChar == 'X') {
                    ans += (firstChar == 'L' ? 40 : 90);
                    i -= 2;
                } else {
                    ans += roman[firstChar];
                    i--;
                }
            } else if (firstChar == 'D' || firstChar == 'M') {
                if (secondChar == 'C') {
                    ans += (firstChar == 'D' ? 400 : 900);
                    i -= 2;
                } else {
                    ans += roman[firstChar];
                    i--;
                }
            } else {
                ans += roman[firstChar];
                i--;
            }
        }
        if (i == 0) ans += roman[s[i]];

        return ans;
    }
};