// O(n) time, O(1) space. Two pointer approach.
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        
        while(l < r) {
            while(l < r and !isalnum(s[l]))     l++;
            while(l < r and !isalnum(s[r]))     r--;
            
            if(tolower(s[l++]) != tolower(s[r--]))
                return false;
        }
        return true;
    }
};
