// O(s•m•n) time and space, where s = size of strs, m = number of zeroes, n = number of ones
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1)));
        
        for(int k = 1; k <= strs.size(); k++) {
            int zeroes = count(strs[k-1].begin(), strs[k-1].end(), '0');
            int ones = strs[k-1].size() - zeroes;
            
            for(int i = 0; i <= m; i++) {
                for(int j = 0; j <= n; j++) {
                    if(i < zeroes or j < ones)  dp[k][i][j] = dp[k-1][i][j];
                    else    dp[k][i][j] = max(dp[k-1][i][j], 1 + dp[k-1][i-zeroes][j-ones]);
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};

/*

Insight:
The problem insight comes from recognizing that it is useful to remember how many strings you could optimally form given some budget of zeros and ones.

We can think of each string as requiring a certain amount of zeros and ones. If our budget of zeros and ones has the required zeros and ones for a string, we can make a choice...
to form the string, spending the required zeros and ones from the budget, or
not to form the string, keeping the budget the same.

Let dp[k][i][j] means the maximum number of strings we can get from the first k argument strs using limited i number of '0's and j number of '1's.

To make this decision, we simply have to compare the two choices! We do this by comparing...
• when forming the string, the optimal number of strings you could form with the now reduced budget, plus the one string you formed, i.e, dp[k][i][j] = 1 + dp[k-1][i-zeroes(str[k])][j-ones(str[k])]
• when not forming the string, the optimal number of strings you could form with the same budget, i.e, dp[k][i][j] = dp[k-1][i][j]

*/
