// O(m + n) time, O(1) space, where m = S.size() and n = T.size()
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size()-1, j = T.size()-1, back = 0;
        
        while(true) {
            back = 0;
            while(i >= 0 and (back or S[i] == '#')) {
                back += (S[i] == '#') ? 1 : -1;
                i--;
            }
            
            back = 0;
            while(j >= 0 and (back or T[j] == '#')) {
                back += (T[j] == '#') ? 1 : -1;
                j--;
            }
            
            if(i >= 0 and j >= 0 and S[i] == T[j])  i--, j--;
            else    break;
        }
        return i == -1 and j == -1;
    }
};
