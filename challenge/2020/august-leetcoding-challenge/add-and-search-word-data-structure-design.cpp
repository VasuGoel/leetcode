struct TrieNode {
    unordered_map<char, TrieNode *> mp;
    bool end;
    TrieNode(): end(false) {}
};

class WordDictionary {
    TrieNode *root {nullptr};
    
public:
    WordDictionary(): root(new TrieNode()) {}
    
    void addWord(string word) {
        TrieNode *cur = root;
        for(char c: word) {
            if(!cur->mp.count(c))   cur->mp[c] = new TrieNode();
            cur = cur->mp[c];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
    bool dfs(string &word, int pos, TrieNode *cur) {
        if(pos == word.size())
            return cur->end;

        char c = word[pos];
        if(c != '.') {
            if(!cur->mp.count(c))   return false;
            return dfs(word, pos+1, cur->mp[c]);
        }
        else {
            for(auto c: cur->mp)
                if(dfs(word, pos+1, c.second))
                    return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
