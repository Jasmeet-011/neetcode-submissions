class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        if(cnt==0)return 0;

        vector<vector<int>>dir{{1,0},{0,1},{-1,0},{0,-1}};
        int time=0;
        while(!q.empty()){
            int sz=q.size();
            bool didRot=false;
            for(int i=0;i<sz;i++){
                auto [r,c]=q.front();
                q.pop();
                for(auto d: dir){
                    int x=r+d[0];
                    int y=c+d[1];
                    if(x<n && y<m && x>=0 && y>=0 && grid[x][y]==1){
                        grid[x][y]=2;
                        didRot=true;
                        cnt--;
                        q.push({x,y});
                    }
                }
            }
            if(didRot)time++;
        }
        return (cnt==0)?time:-1;
        
    }
};
