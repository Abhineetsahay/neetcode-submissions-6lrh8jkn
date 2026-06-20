class Solution {
   private:
    double f(string start, string target,
             unordered_map<string, vector<pair<string, double>>>& adjList,
             unordered_set<string> visit) {
        if (!adjList.count(start) || !adjList.count(target)) {
            return -1.0;
        }
        if (start == target) return 1.0;
        visit.insert(start);

        for (auto& [node, weight] : adjList[start]) {
            if (!visit.count(node)) {
                double res = f(node, target, adjList, visit);
                if (res != -1.0) {
                    return weight * res;
                }
            }
        }
        return -1.0;
    }

   public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adjList;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            adjList[a].push_back({b, values[i]});
            adjList[b].push_back({a, 1.0 / values[i]});
        }

        vector<double> res;

        for (auto& query : queries) {
            unordered_set<string> visit;
            res.push_back(f(query[0], query[1], adjList, visit));
        }
        return res;
    }
};