class Solution {
    void dfs(vector<vector<int>>&adj, int u, vector<bool>&vis){
        if(vis[u])return;
        vis[u]=true;
        for(auto v:adj[u]){
            dfs(adj,v,vis);
        }

    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1)return false;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>vis(n,false);
        dfs(adj,0,vis);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;

    }
};
