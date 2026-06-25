class Solution {
    bool dfs(int u, vector<vector<int>>&adj, vector<bool>&vis, vector<bool>&inrec, stack<int>&st )
    {
        vis[u]=true;
        inrec[u]=true;
        for(auto& v:adj[u]){
            if(!vis[v]){
                if(dfs(v,adj,vis,inrec,st))return true;
            }
            else if (inrec[v]) return true;
        }


        inrec[u]=false;
        st.push(u);
        return false;

    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);
        vector<bool>inrec(n,false);
        stack<int>st;
        for(auto& p:prerequisites){
            int v=p[0];
            int u=p[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj, vis, inrec, st))return {};
            }
        }
        vector<int>ans;
        while(!st.empty()){
            auto t= st.top();
            st.pop();
            ans.push_back(t);
        }
        return ans;
        
    }
};
