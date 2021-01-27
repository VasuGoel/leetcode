// O(m+n) time, O(1) space
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26);
        for(char c: s)  freq[c-'a']++;
        
        for(char c: t) {
            if(!freq[c-'a'])    return c;
            freq[c-'a']--;
        }
        throw runtime_error("");
    }
};
