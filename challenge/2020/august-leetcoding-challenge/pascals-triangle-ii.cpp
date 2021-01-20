// O(rowIndex ^ 2) time, O(rowIndex) space
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret (rowIndex+1);
        ret[0] = 1;
        
        for(int i = 1; i <= rowIndex; i++) {
            for(int j = i; j > 0; j--)
                ret[j] += (j > 0 ? ret[j-1] : 0);
        }
        return ret;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(rowIndex ^ 2) time and space
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ret (rowIndex+1);

        for(int i = 0; i <= rowIndex; i++) {
            ret[i].resize(i+1);
            ret[i][0] = ret[i][i] = 1;
            
            for(int j = 1; j < i; j++)
                ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        }
        return ret.back();
    }
};
