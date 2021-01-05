struct TrieNode {
    unordered_map<char, TrieNode *> mp;
    bool end;
    TrieNode(): end(false) {};
};

class Trie {
    TrieNode *root {nullptr};
    
public:
    /** Initialize your Trie data structure here. */
    Trie(): root(new TrieNode()) {};
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for(char c: word) {
            if(!cur->mp.count(c))   cur->mp[c] = new TrieNode();
            cur = cur->mp[c];
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for(char c: word) {
            if(!cur->mp.count(c))    return false;
            cur = cur->mp[c];
        }
        return cur->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(char c: prefix) {
            if(!cur->mp.count(c))   return false;
            cur = cur->mp[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
