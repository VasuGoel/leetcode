// O(n) time, O(1) space
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        return countVowels(s, 0, n/2-1) == countVowels(s, n/2, n-1);
    }
    
    int countVowels(string &s, int l, int r) {
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
        int res = 0;
        for(int i = l; i <= r; i++)
            res += (vowels.count(tolower(s[i])));
        return res;
    }
};
