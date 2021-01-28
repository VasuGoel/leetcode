// O(log(m • n)) time, O(1) space. Binary search.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m*n-1, mid;
        
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int r = mid / n, c = mid % n;
            
            if(matrix[r][c] == target)
                return true;
            
            if(target > matrix[r][c])
                lo = mid+1;
            else
                hi = mid-1;
        }
        return false;
    }
};


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(m + n) time, O(1) space
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        
        while(i < m and j >= 0) {
            if(matrix[i][j] == target)
                return true;
            
            if(target < matrix[i][j])
                j--;
            else
                i++;
        }
        return false;
    }
};
