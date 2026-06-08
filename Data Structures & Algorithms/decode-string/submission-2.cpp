class Solution {
   public:
    string decodeString(string s) {
        stack<string> str;
        stack<int> count;

        int num = 0;
        string ans = "";

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                str.push(ans);
                count.push(num);

                ans = "";
                num = 0;
            } else if (c == ']') {
                string temp = ans;
                ans = str.top();
                str.pop();
                int cnt = count.top();
                count.pop();

                for (int i = 1; i <= cnt; i++) {
                    ans += temp;
                }
            } else {
                ans += c;
            }
        }
        return ans;
    }
};