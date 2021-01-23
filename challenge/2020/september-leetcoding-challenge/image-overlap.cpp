// O(n^4) time, O(n^2) space
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), res = 0;
        vector<vector<int>> a, b;
        
        // store cells with 1 from matrices A and B, into vector a and b respectively
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j])  a.push_back({i, j});
                if(img2[i][j])  b.push_back({i, j});
            }
        }
        
        // count freq of each vector, (x2-x1)i + (y2-y1)j possible among all pairs, (x1,y1) from a and (x2,y2) from b
        unordered_map<string, int> freq;
        for(auto &p: a) {
            for(auto &q: b) {
                string s = to_string(q[0] - p[0]) + '_' + to_string(q[1] - p[1]);
                res = max(res, ++freq[s]);
            }
        }
        return res;
    }
};
