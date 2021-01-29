// O(n) time, O(1) space
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        
        for(int i = 0, a = 0, b = 0; (A[i] == A[0] or B[i] == A[0]) ; i++) {
            if(A[i] != A[0])    a++;
            if(B[i] != A[0])    b++;
            if(i == n-1)    return min(a, b);
        }
        
        for(int i = 0, a = 0, b = 0; (A[i] == B[0] or B[i] == B[0]) ; i++) {
            if(A[i] != B[0])    a++;
            if(B[i] != B[0])    b++;
            if(i == n-1)    return min(a, b);
        }
        
        return -1;
    }
};

/*

Observe we can only convert each row element to either A[0] each or B[0] each, since any different number A[i] or B[i] in 1 ≤ i ≤ n
would mean it wasn't present in A[0] or B[0] (i.e, we cannot possibly obtain all same numbers in either row).

*/
