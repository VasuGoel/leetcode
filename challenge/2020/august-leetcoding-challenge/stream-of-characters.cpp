struct TrieNode {
    unordered_map<char, TrieNode *> mp;
    bool end;
    TrieNode(): end(false) {};
};

class StreamChecker {
    string s;
    TrieNode *root {nullptr};
    
public:
    // build trie of reverse of words as preprocessing
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(string &word: words) {
            reverse(word.begin(), word.end());
            TrieNode *cur = root;
            
            for(char c: word) {
                if(!cur->mp.count(c))   cur->mp[c] = new TrieNode();
                cur = cur->mp[c];
            }
            cur->end = true;
        }
    }
    
    // starting from current letter and going back to older ones, traverse down trie and check if we hit end
    bool query(char letter) {
        s += letter;
        TrieNode *cur = root;
        
        for(int i = s.size()-1; i >= 0; i--) {
            if(!cur->mp.count(s[i]))    return false;
            cur = cur->mp[s[i]];
            
            if(cur->end)    return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
