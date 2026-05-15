class Solution {
   private:
    bool dfs(int node, int parent, stack<int>& st, vector<int>& InStack, int& stInd,
             vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        st.push(node);
        InStack[node] = 1;

        for (auto& it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, node, st, InStack,stInd, vis, adj)) {
                    return true;
                }
            } else if (it != parent && InStack[it]) {
                stInd = it;
                return true;
            }
        }
        st.pop();
        InStack[node] = 0;
        return false;
    }

   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        stack<int> st;
        vector<int> InStack(n + 1, 0);
        int stInd = -1;
        vector<int> vis(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, st, InStack, stInd, vis, adj)) {
                    break;
                }
            }
        }
        unordered_set<int> nodes;
        int top = -1;
        while (!st.empty()) {
            top = st.top();
            st.pop();
            nodes.insert(top);
            if (top == stInd && stInd != -1) {
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (nodes.count(u) && nodes.count(v)) {
                return {u, v};
            }
        }
        return {};
    }
};
