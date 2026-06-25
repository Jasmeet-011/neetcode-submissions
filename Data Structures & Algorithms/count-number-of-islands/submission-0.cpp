class Solution {
vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i, int j, vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        grid[i][j]='0';
        for(auto d:dir){
            int x=d[0]+i;
            int y=d[1]+j;
            if(x<n && y<m && x>=0 && y>=0 && grid[x][y]=='1'){
                dfs(x,y,grid);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};
