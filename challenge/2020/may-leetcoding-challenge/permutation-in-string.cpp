// O(n) time, O(1) space. Sliding Window approach.
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26);
        for(char c: s1)     freq[c-'a']++;
        
        int l = 0, r = 0, count = s1.size();
        while(r < s2.size()) {
            if(freq[s2[r]-'a'] > 0)     count--;
            freq[s2[r++]-'a']--;
            
            if(!count)  return true;
            
            if(r-l == s1.size()) {
                if(freq[s2[l]-'a'] >= 0)    count++;
                freq[s2[l++]-'a']++;
            }
        }
        return false;
    }
};
