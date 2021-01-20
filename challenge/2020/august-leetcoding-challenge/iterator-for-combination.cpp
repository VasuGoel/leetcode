class CombinationIterator {
    int pos;
    vector<string> combinations;
    
public:
    CombinationIterator(string characters, int combinationLength): pos(0) {
        // generate all possible 'combinationLength' combinations of 'characters'
        combinations = dfs(characters, 0, combinationLength);
    }
    
    string next() {
        return combinations[pos++];
    }
    
    bool hasNext() {
        return pos != combinations.size();
    }
    
    vector<string> dfs(string &s, int pos, int k) {
        vector<string> ret;
        if(!k) {
            ret.push_back("");
            return ret;
        }
        
        for(int i = pos; i <= s.size()-k; i++) {
            vector<string> remain = dfs(s, i+1, k-1);
            
            for(string &r: remain)
                ret.push_back(s[i] + r);
        }
        return ret;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
