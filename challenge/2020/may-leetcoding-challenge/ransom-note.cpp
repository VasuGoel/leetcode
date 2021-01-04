// O(m + n) time, O(1) space, where m = ransomNote length, and n = magazine length
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26);
        for(char m: magazine)   freq[m-'a']++;
        
        for(char r: ransomNote) {
            if(!freq[r-'a'])    return false;
            freq[r-'a']--;
        }
        return true;
    }
};
