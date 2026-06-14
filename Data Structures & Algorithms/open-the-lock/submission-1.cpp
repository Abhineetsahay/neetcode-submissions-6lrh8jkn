class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> visit(deadends.begin(), deadends.end());

        if(visit.count("0000")) return -1;
        queue<pair<string, int>> q;

        q.push({"0000", 0});
        visit.insert("0000");

        int ans = 0;

        while (!q.empty()) {
            string curr = q.front().first;
            int turn = q.front().second;

            if (curr == target) return turn;
            q.pop();

            vector<string> children;

            for (int i = 0; i < 4; i++) {
                string newChild = curr;
                newChild[i] = (newChild[i] - '0' + 1) % 10 + '0';

                children.push_back(newChild);

                newChild = curr;
                newChild[i] = (newChild[i] - '0' - 1 + 10) % 10 + '0';
                children.push_back(newChild);
            }

            for (auto& child : children) {
                if (visit.find(child) == visit.end()) {
                    visit.insert(child);
                    q.push({child, turn + 1});
                }
            }
        }
        return -1;
    }
};