// O(n) time and space
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> freq1, freq2, values;
        
        for(char &c: word1)  freq1[c]++;
        for(char &c: word2)  freq2[c]++;
        
        for(auto &f: freq2) {
            if(!freq1.count(f.first))   return false;
            values[f.second]++;
        }

        for(auto &f: freq1)
            if(--values[f.second] < 0)  return false;

        return true;
    }
};

/*

Idea - We only need to check for 2 conditions

• All the unique char which are there in word1 need to be there as well in word2
• Frequency of chars need to be same for both of string as we can ransform every occurrence 
  of one existing character into another existing character

*/
