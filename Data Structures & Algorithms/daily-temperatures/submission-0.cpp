class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> result(n, 0);
        stack<pair<int, int>> st;  //{ind,value}

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().second <= temperatures[i]) {
                st.pop();
            }

            if (!st.empty()) {
                result[i] = st.top().first - i;
            }
            st.push({i, temperatures[i]});
        }
        return result;
    }
};
