class Solution {
    void dfs(int u, vector<vector<int>>&adj, vector<int>&vis){
        vis[u]=1;
        for(auto& v:adj[u]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);

        for(auto& e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;

    }
};
