// O(m + n) time, O(1) space, where m = word1.size() and n = word2.size()
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size(), n = word2.size(), w1 = 0, w2 = 0, i = 0, j = 0;
        
        // two pointers 'w1' and 'w2' to track word in arrays, and two pointers 'i' and 'j' to track character in each word
        while(w1 < m and w2 < n) {
            if(word1[w1][i++] != word2[w2][j++])    return false;
            
            if(i == word1[w1].size())  w1++, i = 0;
            if(j == word2[w2].size())  w2++, j = 0;
        }
        return w1 == m and w2 == n;
    }
};
