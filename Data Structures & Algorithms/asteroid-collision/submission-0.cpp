class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {
            bool destroyed = false;
            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (abs(asteroid) > st.top()) {
                    st.pop();
                } else if (abs(asteroid) == st.top()) {
                    destroyed = true;
                    st.pop();
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                st.push(asteroid);
            }
        }
        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};