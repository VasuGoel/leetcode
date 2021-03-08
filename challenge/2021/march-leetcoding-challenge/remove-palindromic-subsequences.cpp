// O(n) time, O(1) space
class Solution {
public:
    int removePalindromeSub(string s) {
        return s.empty() ? 0 : (s == string(s.rbegin(), s.rend()) ? 1 : 2);
    }
};

/*

• if s is empty, return 0
• if s is palindrome, return 1
• otherwise, return 2 (remove all a's first then all b's, since s only consists of letter 'a' and 'b')

*/
