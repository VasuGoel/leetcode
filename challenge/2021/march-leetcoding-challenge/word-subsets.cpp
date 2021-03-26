// O((m + n) • k) time, O(26) space, where n = size of A, m = size of B, k = max length of A[i] and B[i]
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> count (26), freq (26);
        vector<string> ret;
        
        for(string b: B) {
            freq = counter(b);
            for(int i = 0; i < 26; i++)
                count[i] = max(count[i], freq[i]);
        }
        
        int i = 0;
        for(string a: A) {
            freq = counter(a);
            for(i = 0; i < 26; i++)
                if(freq[i] < count[i])
                    break;

            if(i == 26) ret.push_back(a);
        }
        return ret;
    }
    
    vector<int> counter(string s) {
        vector<int> freq (26);
        for(char c: s)  freq[c-'a']++;
        return freq;
    }
};
