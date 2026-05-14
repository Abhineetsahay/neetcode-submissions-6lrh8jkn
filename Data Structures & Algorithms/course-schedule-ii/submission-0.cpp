class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[v].push_back(u);
        }

        vector<int> Indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            for (auto it : adjList[i]) {
                Indegree[it]++;
            }
        }

        queue<int> q;
        vector<int> courses;
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
            courses.push_back(node);
            for (auto nde : adjList[node]) {
                Indegree[nde]--;
                if (Indegree[nde] == 0) {
                    q.push(nde);
                }
            }
        }
        if (cnt != numCourses) return {};

        return courses;
    }
};
