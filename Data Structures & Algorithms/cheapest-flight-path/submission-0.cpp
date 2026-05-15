class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];

            adj[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, INT_MAX);
        q.push({0, {src, 0}});
        dist[src] = 0;

        while (!q.empty()) {
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if (stop > k) continue;

            for (auto& it : adj[node]) {
                if (cost + it.second < dist[it.first] && stop <= k) {
                    dist[it.first] = cost + it.second;
                    q.push({stop + 1, {it.first, dist[it.first]}});
                }
            }
        }
        if (dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};
