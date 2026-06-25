class Solution {
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs1(int i, int j, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        board[i][j] ='#';
        for (auto& d : dir) {
            int x = i + d[0];
            int y = j + d[1];
            if (x < n && y < m && x >= 0 && y >= 0 && board[x][y] == 'O') {
                dfs1(x, y, board);
            }
        }
    }
    void dfs2(int i, int j, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        board[i][j] = 'X';
        for (auto& d : dir) {
            int x = i + d[0];
            int y = j + d[1];
            if (x < n && y < m && x >= 0 && y >= 0 && board[x][y] == 'O') {
                dfs2(x, y, board);
            }
        }
    }

   public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            if (board[i][0] == 'O') {
                dfs1(i, 0, board);
            }
            if (board[i][m-1] == 'O') {
                dfs1(i, m-1, board);
            }
        }
        
        for(int j = 0; j < m; j++){
            if (board[0][j] == 'O') {
                dfs1(0, j, board);
            }
            if (board[n-1][j] == 'O') {
                dfs1(n-1, j, board);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') dfs2(i, j, board);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
