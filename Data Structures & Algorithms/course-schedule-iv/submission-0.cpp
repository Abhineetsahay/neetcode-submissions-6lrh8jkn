class Solution {
   public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<unordered_set<int>> adjList(numCourses), preReq(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].insert(v);
        }

        vector<int> Indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            for (auto it : adjList[i]) {
                Indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (Indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nde : adjList[node]) {
                preReq[node].insert(node);
                for (auto x : preReq[node]) preReq[nde].insert(x);
                Indegree[nde]--;
                if (Indegree[nde] == 0) {
                    q.push(nde);
                }
            }
        }
        vector<bool> res;
        for (auto& query : queries) {
            res.push_back(preReq[query[1]].count(query[0]));
        }
        return res;
    }
};