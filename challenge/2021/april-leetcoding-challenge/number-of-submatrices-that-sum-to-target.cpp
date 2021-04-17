// O(m•n^2) time, O(n) space
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j - 1];

        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                map = {{0,1}};
                int cur = 0;
                for (int k = 0; k < m; k++) {
                    cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    res += map.count(cur - target) ? map[cur - target] : 0;
                    map[cur]++;
                }
            }
        }
        return res;
    }
};

// Ref: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/discuss/303750/JavaC%2B%2BPython-Find-the-Subarray-with-Target-Sum