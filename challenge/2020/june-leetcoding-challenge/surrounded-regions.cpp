// DFS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())   return;
        int m = board.size(), n = board[0].size();
        
        // iterate over borders, dfs on 'O' cells and keep changing all adjacent connected cells having 'O' with '#' (visited symbol)
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O')      dfs(board, i, 0);
            if(board[i][n-1] == 'O')    dfs(board, i, n-1);
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O')      dfs(board, 0, j);
            if(board[m-1][j] == 'O')    dfs(board, m-1, j);
        }
        
        // 'O' cells within matrix after all dfs from border cells having 'O' are definitely surrounded with 'X' and hence changed to 'X', also revert back all '#' to 'O'
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O')  board[i][j] = 'X';
                if(board[i][j] == '#')  board[i][j] = 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>> &board, int i, int j) {
        if(i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or board[i][j] == 'X' or board[i][j] == '#')
            return;
        
        board[i][j] = '#';
        dfs(board, i-1, j); 
        dfs(board, i, j+1);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
    }
};
