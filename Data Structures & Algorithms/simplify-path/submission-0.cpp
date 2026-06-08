class Solution {
   public:
    string simplifyPath(string path) {
        stack<string> st;

        string token;
        stringstream ss(path);

        while (getline(ss, token, '/')) {
            if (token.empty() || token == ".") {
                continue;
            }

            if (token == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(token);
            }
        }
        string ans = "";
        vector<string> paths;
        while (!st.empty()) {
            paths.push_back(st.top());
            st.pop();
        }
        reverse(paths.begin(), paths.end());

        for (string& path : paths) {
            ans += ('/' + path);
        }
        return ans.empty() ? "/" : ans;
    }
};