// O(n) time, O(1) space
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for(int r = 0, l = 0; r < A.size(); r++) {
            if((A[r] & 1) == 0)
                swap(A[l++], A[r]);
        }
        return A;
    }
};

/*

• Pointer l denotes index where next even number is to be placed
• Do a linear scan, swap any even number with number at index l
• Resultant array will have even number followed by odd number

*/
