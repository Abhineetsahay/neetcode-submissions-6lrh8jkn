class Solution {
   private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vector<int>vis(n,0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i, adj, vis);
            }
        }
        return ans;
    }
};
