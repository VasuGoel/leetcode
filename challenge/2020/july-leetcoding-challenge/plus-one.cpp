// O(n) time, O(1) space
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1, carry = 1;
        
        while(i >= 0 and carry) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i--] %= 10;
        }
        if(carry)
            digits.insert(digits.begin(), carry);
        
        return digits;
    }
};
