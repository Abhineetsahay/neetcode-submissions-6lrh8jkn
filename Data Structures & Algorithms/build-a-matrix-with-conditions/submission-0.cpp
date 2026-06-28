class Solution {
   private:
    vector<int> topoSort(int k, vector<vector<int>> adj) {
        vector<int> ans;
        vector<int> inDegree(k + 1, 0);

        for (int i = 1; i <= k; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return ans;
    }

   public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<vector<int>> rowGraph(k + 1), colGraph(k + 1);

        for (int i = 0; i < rowConditions.size(); i++) {
            int u = rowConditions[i][0];
            int v = rowConditions[i][1];
            rowGraph[u].push_back(v);
        }

        for (int i = 0; i < colConditions.size(); i++) {
            int u = colConditions[i][0];
            int v = colConditions[i][1];
            colGraph[u].push_back(v);
        }

        vector<int> rowInd = topoSort(k, rowGraph);
        vector<int> colInd = topoSort(k, colGraph);

        if (rowInd.size() != k || colInd.size() != k) return {};

        unordered_map<int, int> rowPos, colPos;

        for (int i = 0; i < rowInd.size(); i++) {
            rowPos[rowInd[i]] = i;
            colPos[colInd[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (int i = 1; i <= k; i++) {
            ans[rowPos[i]][colPos[i]] = i;
        }
        return ans;
    }
};