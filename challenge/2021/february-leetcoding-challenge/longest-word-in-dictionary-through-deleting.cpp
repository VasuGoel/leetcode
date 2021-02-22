// O(n • k) time, O(1) space, where n = size of s, and k = number of words in d
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        // sort words in d based on decreasing length and lexicographically when word lengths are same
        sort(d.begin(), d.end(), [&](auto a, auto b) -> bool {
            return a.size() > b.size() or (a.size() == b.size() and a < b);
        });
        
        for(string word: d) {
            if(isSubsequence(s, word))
                return word;
        }
        return "";
    }
    
    // check if string b is a subsequence of string a
    bool isSubsequence(string &a, string &b) {
        int i = 0;
        for(char c: a) {
            i += (c == b[i]) ? 1 : 0;
            if(i == b.size())
                return true;
        }
        return false;
    }
};
