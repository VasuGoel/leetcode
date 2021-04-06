class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i)
            if (abs(A[i] - i) > 1) 
                return false;
        return true;
    }
};

// Ref: https://leetcode.com/problems/global-and-local-inversions/discuss/113644/C%2B%2BJavaPython-Easy-and-Concise-Solution