// O(n) time and space
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        
        int n = pattern.size(), i = 0;
        string word;
        istringstream ss(s);

        while(i < n and ss >> word) {
            char c = pattern[i];
            if((mp1.count(c) and mp1[c] != word) or (mp2.count(word) and mp2[word] != c))
                return false;
            
            mp1[c] = word, mp2[word] = c;
            i++;
        }
        
        return i == n and !ss.good();
    }
};
