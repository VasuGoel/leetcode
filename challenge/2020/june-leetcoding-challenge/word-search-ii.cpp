struct TrieNode {
    unordered_map<char, TrieNode *> mp;     // hold mapping between character and child TrieNode
    bool end;                               // marks end of word
    string word;                            // holds complete word when marked as end
    TrieNode(): end(false) {};
};

class Solution {    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = buildTrie(words);      // returns root of trie data structure after building
        
        int m = board.size(), n = board[0].size();
        unordered_set<string> ret;      // store found words in set to avoid duplicates
        // for each cell of the board recursively check if character is present in trie nodes
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, i, j, root, ret);
            }
        }
        return {ret.begin(), ret.end()};
    }
    
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *cur, unordered_set<string> &ret) {
        // handles out of bounds or if board character is not present in trie node
        if(i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or !cur->mp.count(board[i][j]))
            return;
        
        // if current board character is found in trie node move node control to child of that character
        if(cur->mp.count(board[i][j]))  
            cur = cur->mp[board[i][j]];
         // check if node is marked as end of word and push word stored in that node to set of found words
        if(cur->end)    
            ret.insert(cur->word);
        
        char c = board[i][j];       // store board[i][j] temporarily in variable
        board[i][j] = '#';          // invalidate cell to avoid reusing it in same word
        
        // recursively check if characters to the up, right, down or left of current board character can be included in words to search
        dfs(board, i-1, j, cur, ret);
        dfs(board, i, j+1, cur, ret);
        dfs(board, i+1, j, cur, ret);
        dfs(board, i, j-1, cur, ret);
        
        board[i][j] = c;            // undo/backtrack changes to cell
    }
    
    // build trie data structure from words to search
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        // iteratively populate trie nodes
        for(string word: words) {
            TrieNode *cur = root;
            for(char c: word) {
                // if character does not exist in map of current trie node
                if(!cur->mp.count(c))   cur->mp[c] = new TrieNode();    // add character with new child trie node
                cur = cur->mp[c];       // move trie node pointer to child node
            }
            cur->end = true;            // mark node as end of word
            cur->word = word;           // store complete word in that node
        }
        return root;
    }
};
