// O(m + n) time, O(1) space. Two pointer approach.
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = B.size(), i = 0, j = 0;
        vector<vector<int>> ret;

        while(i < m and j < n) {
            // if intervals A[i] and B[j] intersect, push their intersection in 'res'
            if(A[i][0] <= B[j][1] and A[i][1] >= B[j][0])
                ret.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
            
            // advance i or j based on which interval ends first
            if(A[i][1] < B[j][1])   i++;
            else    j++;
        }
        return ret;
    }
};
