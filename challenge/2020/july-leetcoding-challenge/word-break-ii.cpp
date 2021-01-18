// DFS (with memoization). Similar to palindrome partitioning.
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict (wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;    // used for memoization
        return dfs(s, 0, dict, memo);
    }
    
    vector<string> dfs(string &s, int pos, unordered_set<string> &dict, unordered_map<int, vector<string>> &memo) {
        vector<string> ret;
        if(pos == s.size()) {
            ret.push_back("");
            return ret;
        }
        if(memo.count(pos))         // return results at 'pos' index, if stored earlier
            return memo[pos];
        
        for(int i = pos; i < s.size(); i++) {
            string word = s.substr(pos, i-pos+1);
            if(dict.count(word)) {
                vector<string> remain = dfs(s, i+1, dict, memo);
                
                for(string &r: remain)
                    ret.push_back(word + (r.empty() ? "" : " ") + r);
            }
        }
        return memo[pos] = ret;     // memoize results at 'pos' index
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// DFS (without memoization). Recursive calls return vector of strings. [TLE]
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict (wordDict.begin(), wordDict.end());
        return dfs(s, 0, dict);
    }
    
    vector<string> dfs(string &s, int pos, unordered_set<string> &dict) {
        vector<string> ret;
        if(pos == s.size()) {
            /*                
                added to avoid 'ret' from being empty, so we can enter the for loop 'for(string &r: remain)', 
                to start building up the sentences (if we remove it, output would be empty, since we cannot start 
                bubbling up if we cannot enter the for loop, when base condition of exhausting entire string is hit)
            */
            ret.push_back("");
            return ret;
        }
        
        // try all indices starting from 'pos', to find a valid word
        for(int i = pos; i < s.size(); i++) {
            string word = s.substr(pos, i-pos+1);
            // if valid word is found from [pos, i]
            if(dict.count(word)) {
                // recur and return vector of sentences from remaining substring from [i+1, s.size())
                vector<string> remain = dfs(s, i+1, dict);
                
                // add this valid word to valid sentences from remaining substring
                for(string &r: remain)
                    ret.push_back(word + (r.empty() ? "" : " ") + r);
            }
        }
        return ret;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Another approach - Recursive calls don't return anything (no memoization possible) [TLE]
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict (wordDict.begin(), wordDict.end());
        
        vector<vector<string>> ret;
        dfs(s, 0, vector<string>()={}, ret, dict);
        
        vector<string> res;
        for(vector<string> &r: ret) {
            string str;
            for(string &word: r)    str += word;
            res.push_back(str);
        }
        return res;
    }
    
    void dfs(string &s, int pos, vector<string> &path, vector<vector<string>> &ret, unordered_set<string> &dict) {
        if(pos == s.size()) {
            ret.push_back(path);
            return;
        }
        
        for(int i = pos; i < s.size(); i++) {
            string word = s.substr(pos, i-pos+1);
            if(dict.count(word)) {
                path.push_back(word + (i+1 == s.size() ? "" : " "));
                dfs(s, i+1, path, ret, dict);
                path.pop_back();
            }
        }
    }
};
