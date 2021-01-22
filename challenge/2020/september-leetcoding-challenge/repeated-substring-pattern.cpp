class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2*s.size()-2).find(s) != string::npos;
    }
};

/*

Ex: s = "abcabc"

• Duplicate it to get "abcabc" + "abcabc" = "abcabcabcabc"
• Remove first and last character to get "bcabcabcab"
• If there is a repeated substring in original string s, then we should be able to find string s
within this new string, "bc|abcabc|ab"
                            ––––––
*/
