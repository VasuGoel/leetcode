// O(n) time, O(1) space, where n = length of t
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(char c: t)
            if(s[i] == c)   i++;
        return i == s.size();
    }
};
