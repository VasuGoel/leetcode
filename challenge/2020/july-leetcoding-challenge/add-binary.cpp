// O(m + n) time and space, where m = length of a, n = length of b
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size()-1, j = b.size()-1;
        int sum = 0, carry = 0;
        
        while(i >= 0 or j >= 0 or carry) {
            sum = (i >= 0 ? a[i--]-'0' : 0) + (j >= 0 ? b[j--]-'0' : 0) + carry;
            res = (char)(sum % 2 + '0') + res;
            carry = sum / 2;
        }
        return res;
    }
};
