class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());
        vector<int> ans;

        int i = 0;
        long time = 0;
        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                time = max(time, (long)tasks[i][0]);
            }

            while (i < n && time >= tasks[i][0]) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            time += pq.top().first;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};