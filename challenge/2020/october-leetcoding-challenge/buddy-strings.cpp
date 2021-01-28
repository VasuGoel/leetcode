// O(n) time, O(1) space
class Solution {
public:
    bool buddyStrings(string A, string B) {
        int m = A.size(), n = B.size();
        if(m != n)  return false;
        
        int mismatches = 0, maxfreq = 0;
        string a, b;
        vector<int> freq(26);
        
        for(int i = 0; i < n; i++) {
            if(A[i] != B[i])
                a += A[i], b += B[i], mismatches++;
            else
                maxfreq = max(maxfreq, ++freq[A[i]-'a']);
            
            if(mismatches > 2)  return false;
        }
        
        return (a.empty() and maxfreq > 1) or (a.size() == 2 and a[0] == b[1] and a[1] == b[0]);
    }
};
