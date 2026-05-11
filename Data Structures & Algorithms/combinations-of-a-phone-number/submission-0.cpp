class Solution {
   private:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    void f(int i, string curStr, string& digits) {
        if (curStr.size() == digits.size()) {
            res.push_back(curStr);
            return;
        }

        string chars = digitToChar[digits[i] - '0'];

        for (char c : chars) {
            f(i + 1, curStr + c, digits);
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        string curStr = "";
        f(0, curStr, digits);
        return res;
    }
};
