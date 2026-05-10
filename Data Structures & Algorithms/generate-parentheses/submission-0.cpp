class Solution {
   private:
    void f(int openP, int closeP, int n, string s, vector<string>& res) {
        if (openP == closeP && openP + closeP == 2 * n) {
            res.push_back(s);
            return;
        }

        if (openP < n) {
            f(openP + 1, closeP, n, s + '(', res);
        }
        if (closeP < openP) {
            f(openP, closeP + 1, n, s + ')', res);
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        f(0, 0, n, "", res);
        return res;
    }
};
