class Solution {
   private:
    bool isPalin(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void f(int i, int n, string& s, vector<string>& subStr, vector<vector<string>>& res) {
        if (i >= n) {
            res.push_back(subStr);
            return;
        }
        for (int j = i; j < n; j++) {
            if (isPalin(s, i, j)) {
                subStr.push_back(s.substr(i, j - i + 1));
                f(j + 1, n, s, subStr, res);
                subStr.pop_back();
            }
        }
    }

   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subStr;

        f(0, s.size(), s, subStr, res);
        return res;
    }
};
