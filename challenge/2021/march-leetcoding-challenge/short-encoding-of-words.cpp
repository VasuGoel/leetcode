// O(n•k•k) time, O(n•k) space, where n = words.length, k = max len of words[i]
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s (words.begin(), words.end());
        
        // iterate over all words in hashset
        for(auto word: s) {
            // remove all suffixes of each word from hashset
            for(int l = 1; l <= word.size(); l++)
                s.erase(word.substr(l));
        }
        
        // hashset now contains only encoding words
        int res = 0;
        for(auto word: s)
            res += word.size() + 1;
        return res;
    }
};
