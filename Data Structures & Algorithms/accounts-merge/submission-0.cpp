class DSU {
   public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void UnionBySize(int x, int y) {
        int x_par = find(x);
        int y_par = find(y);

        if (x_par == y_par) return;
        if (size[x_par] < size[y_par]) {
            parent[x_par] = y_par;
            size[y_par] += size[x_par];
        } else {
            parent[y_par] = x_par;
            size[x_par] += size[y_par];
        }
    }
};
class Solution {
   public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mp;
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                } else {
                    dsu.UnionBySize(i, mp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> mapedMail(n);
        for (auto& it : mp) {
            string mail = it.first;
            int pr = dsu.find(it.second);
            mapedMail[pr].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mapedMail[i].size() == 0) continue;

            sort(mapedMail[i].begin(), mapedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto& it : mapedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};