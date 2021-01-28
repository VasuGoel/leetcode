// O(n) time and space
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 'freq' stores frequency of each character in s, and 'used' tracks characters already used in result string
        vector<int> freq(128), used(128);
        for(char c: s)  freq[c]++;
        
        string res;
        for(char c: s) {
            // decrement freq of c (after traversing)
            freq[c]--;
            // skip char if already present in result (avoid duplicates)
            if(used[c])     continue;
            
            // maintain a monotonically increasing string, if current char is smaller than last char in result and if that 
            // last char is present further in original string (freq > 0) then pop it from result (it will be added later), and mark last char as unused
            while(!res.empty() and c < res.back() and freq[res.back()] > 0)
                used[res.back()] = 0, res.pop_back();
            
            // add char to result and mark as used
            res += c;
            used[c] = 1;
        }
        return res;
    }
};
