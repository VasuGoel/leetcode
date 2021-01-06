// Sliding window approach. O(n) time, O(1) space.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {        
        vector<int> ret, freq(26);
        for(char c: p)  freq[c-'a']++;
        
        int l = 0, r = 0, count = p.size();
        while(r < s.size()) {
            if(freq[s[r]-'a'] > 0)  count--;
            freq[s[r++]-'a']--;
            
            if(!count)  ret.push_back(l);
            
            // when r-l equals window size
            if(r-l == p.size()) {
                if(freq[s[l]-'a'] >= 0)  count++;
                freq[s[l++]-'a']++;
            }
        }
        return ret;
    }
};
