// DFS
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                if(board[i][j] == word[0] and dfs(board, i, j, 0, word))
                    return true;
        }
        return false;
    }
    
    bool dfs(vector<vector<char>> &board, int i, int j, int pos, string word) {
        if(pos == word.size())
            return true;
        if(i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or board[i][j] != word[pos])
            return false;

        char c = board[i][j];
        board[i][j] = '#';
        
        bool res = dfs(board, i-1, j, pos+1, word) or dfs(board, i, j+1, pos+1, word) or 
                   dfs(board, i+1, j, pos+1, word) or dfs(board, i, j-1, pos+1, word);
        
        board[i][j] = c;
        return res;
    }
};
