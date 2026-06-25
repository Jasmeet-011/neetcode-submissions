class Solution {
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(queue<pair<int,int>>&q, vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            auto [r, c]=q.front();
            q.pop();
            for(auto d:dir){
                int x= r+d[0];
                int y=c+d[1];
                if(x<n && y<m && x>=0 && y>=0 && grid[x][y]>grid[r][c]+1){
                    grid[x][y]=grid[r][c]+1;
                    q.push({x,y});
                }
            }
        }
        return;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    bfs(q,grid);
                }
            }
        }
    }
};
