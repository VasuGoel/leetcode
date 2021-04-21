// DP. O(n^2) time, O(n) space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> minpath = triangle.back();

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                minpath[j] = triangle[i][j] + min(minpath[j], minpath[j+1]);
            }
        }
        return minpath[0];
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// DP. O(n^2) time, O(1) space (Destructive, modifies triangle, hence thread unsafe)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // iterate from second-last to row 0 
        for(int i = n-2; i >= 0; i--) {
            // update value at each col 'j' of row 'i', with value at cell itself + min(adjacent left cell below, adjacent right cell below)
            for(int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];      // triangle top will be updated with min path sum
    }
};
