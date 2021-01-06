// Sliding window approach. O(n) time, O(1) space.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {        
        vector<int> ret, freq(128);
        for(char c: p)  freq[c]++;
        
        int l = 0, r = 0, count = p.size();
        while(r < s.size()) {
            if(freq[s[r]] > 0)  count--;
            freq[s[r++]]--;
            
            if(!count)  ret.push_back(l);
            
            // when r-l equals window size
            if(r-l == p.size()) {
                if(freq[s[l]] >= 0)  count++;
                freq[s[l++]]++;
            }
        }
        return ret;
    }
};
