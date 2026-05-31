class Solution {
   public:
    int calPoints(vector<string>& operations) {
        int sum = 0;

        stack<int> st;
        for (string& operation : operations) {
            if (operation == "+") {
                int score1 = st.top();
                st.pop();
                int score2 = st.top();
                st.pop();

                int score3 = score1 + score2;
                st.push(score2);
                st.push(score1);
                st.push(score3);
            }
            else if (operation == "D") {
                int topScore = st.top();
                st.push(topScore * 2);
            } else if (operation == "C") {
                st.pop();
            } else {
                st.push(stoi(operation));
            }
        }

        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};