class Solution {
    vector<vector<int>> dir= {{1,0},{0,1},{-1,0},{0,-1}};
    int BFS(int i, int j, vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=0;
        int cnt=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto [r, c]=q.front();
                q.pop();
                for(auto d: dir){
                    int x=d[0]+r;
                    int y=d[1]+c;
                    if(x<n &&y<m &&x>=0 && y>=0 &&grid[x][y]==1){
                        grid[x][y]=0;
                        q.push({x,y});
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int x=BFS(i,j,grid);
                    maxi=max(maxi,x);
                }
            }
        }
        return maxi;

        
    }
};
