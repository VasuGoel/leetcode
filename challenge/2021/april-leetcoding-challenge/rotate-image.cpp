class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        // for all square sub-matrices in n x n matrix
        for(int i = 0; i < n/2; i++) {
            // each sub-matrix will be rotated n-1-i times
            for(int j = i; j < n-1-i; j++) {
                int temp = matrix[i][j];
                swap(temp, matrix[j][n-1-i]);
                swap(temp, matrix[n-1-i][n-1-j]);
                swap(temp, matrix[n-1-j][i]);
                swap(temp, matrix[i][j]);
            }
        }
    }
};
