// O(N • K) time, O(1) space, where N = size of words, and K = max size of words[i]
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mapping(26);
        
        for(int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        
        for(string &word: words) {
            for(char &c: word)
                c = mapping[c-'a'];
        }
        return is_sorted(words.begin(), words.end());
    }
};
