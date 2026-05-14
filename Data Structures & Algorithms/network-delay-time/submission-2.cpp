class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto time : times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];

            adj[u].push_back({v, t});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // time, node
        pq.push({0, k});

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                if (dist[node] + it.second < dist[it.first]) {
                    dist[it.first] = dist[node] + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        int minTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            minTime = max(minTime, dist[i]);
        }
        return minTime;
    }
};
