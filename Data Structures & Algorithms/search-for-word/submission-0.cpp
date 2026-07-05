class Solution {
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int s) {
        int n = board.size();
        int m = board[0].size();

        
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[s]) {
            return false;
        }

        
        if (s == word.size() - 1) return true;

        char temp = board[i][j];
        board[i][j] = '#';   

        for (auto d : dir) {
            int x = i + d[0];
            int y = j + d[1];

            
            if (dfs(board, x, y, word, s+1)) {
                board[i][j] = temp;
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};