// O(n) time, O(1) space
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, seq = 0;
        
        for(int i = 2; i < A.size(); i++) {
            if(A[i] - A[i-1] == A[i-1] - A[i-2]) {
                seq++;
                res += seq;
            }
            else
                seq = 0;
        }
        return res;
    }
};
