class Solution {
    void solve(int row, int n,vector<vector<string>>&ans, vector<int>&colUsed,vector<int>&dia1,vector<int>&dia2, vector<string>&board){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0; col<n;col++){
            int d1= row+col;
            int d2= row-col+n;
            if(colUsed[col]|| dia1[d1]|| dia2[d2])continue;

            board[row][col]='Q';
            colUsed[col]= dia1[d1]=dia2[d2]=1;
            solve(row+1, n, ans, colUsed, dia1, dia2,board);
            board[row][col]='.';
            colUsed[col]= dia1[d1]=dia2[d2]=0;

        }    
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<int>colUsed(n,0);
        vector<int>dia1(2*n,0);
        vector<int>dia2(2*n,0);
        vector<string>board(n,string(n,'.'));
        solve(0, n, ans, colUsed, dia1, dia2,board);
        return ans;
    }
};
