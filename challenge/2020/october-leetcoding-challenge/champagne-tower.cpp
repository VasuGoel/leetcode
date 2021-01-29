// O(row^2) time and space. Set poured quantity in first cup and iteratively divide for children cups.
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(query_row+2, vector<double>(query_row+2));
        tower[0][0] = poured;
        
        for(int i = 0; i <= query_row; i++) {
            for(int j = 0; j <= i; j++) {
                if(tower[i][j] > 1) {
                    tower[i+1][j]   += (tower[i][j] - 1) / 2;
                    tower[i+1][j+1] += (tower[i][j] - 1) / 2;
                    tower[i][j] = 1;
                }
            }
        }
        return tower[query_row][query_glass];
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(row^2) time, O(row) space. Space optimized.
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> tower (query_row+2);
        tower[0] = poured;
        
        for(int i = 1; i <= query_row; i++) {
            for(int j = i; j >= 0; j--) {
                tower[j] = max(0.0, (tower[j]-1) / 2);
                tower[j+1] += tower[j];
            }
        }
        return min(tower[query_glass], 1.0);
    }
};
