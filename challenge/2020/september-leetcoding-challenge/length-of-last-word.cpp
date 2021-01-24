// O(n) time, O(1) space
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1, len = 0;
        
        while(i >= 0 and isspace(s[i]))     i--;
        while(i >= 0 and !isspace(s[i]))    
            i--, len++;
        return len;
    }
};
