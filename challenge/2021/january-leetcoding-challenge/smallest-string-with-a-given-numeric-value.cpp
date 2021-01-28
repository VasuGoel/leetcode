// O(n) time, O(1) space
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = string(n, 'a');
        k -= n;
        
        int i = n-1;
        while(k > 0) {
            int offset = min(25, k);
            k -= offset;
            res[i] += offset;
            i--;
        }
        return res;
    }
};

/*

• The idea is simple:
    - Build the string of length k, which consists of letter 'a' (lexicographically smallest string)
    - Increment string from right to left until it's value won't reach the target.

*/
