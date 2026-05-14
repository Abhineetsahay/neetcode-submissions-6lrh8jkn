class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
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

        int cnt = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for (auto nde : adjList[node]) {
                Indegree[nde]--;
                if (Indegree[nde] == 0) {
                    q.push(nde);
                }
            }
        }
        if (cnt != numCourses) return false;
        return true;
    }
};