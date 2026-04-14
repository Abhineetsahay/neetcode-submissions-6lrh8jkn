class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        queue<pair<int,int>>q;
        q.push({0,-1});
        vector<int>vis(n,0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto& adjNode:adjList[node]){
                if(!vis[adjNode]){
                    vis[adjNode]=1;
                    q.push({adjNode,node});
                }
                else{
                    if(adjNode!=parent){
                        return false;
                    }
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(!vis[i]) return false;
        }
        return true;
    }
};
