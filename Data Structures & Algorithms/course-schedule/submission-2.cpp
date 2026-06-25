class Solution {
private:
    bool dfs(int u, vector<bool>&vis,vector<bool>&inrec ,vector<vector<int>>& adj){
        vis[u]=true;
        inrec[u]=true;
        for(auto& v:adj[u]){
            if(!vis[v]){
                if(dfs(v,vis,inrec,adj))return true;
            }
            else if (inrec[v]) return true;
        }
        inrec[u]=false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<bool>vis(n,false);  
        vector<bool>inrec(n,false);  
        for(auto&p: prerequisites){
            int v=p[0];
            int u=p[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,inrec,adj)) return false;
            }
        }
        return true;
        
    }
};
