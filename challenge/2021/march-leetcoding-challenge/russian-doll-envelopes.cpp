
/*
Longest Increasing Subsequence in 2 dimensions. O(nlogn) time, O(n) space

This problem is asking for LIS in two dimensions, width and height. Sorting the width reduces the problem by one dimension. 
If width is strictly increasing, the problem is equivalent to finding LIS in only the height dimension. However, when there is a tie in width, a strictly increasing sequence in height may not be a correct solution. 
For example, [[3,3] cannot fit in [3,4]]. Sorting height in descending order when there is a tie prevents such a sequence to be included in the solution.
*/
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](auto a, auto b) -> bool {
            return a[0] < b[0] or (a[0] == b[0] and a[1] > b[1]);
        });
        
        vector<int> lis;
        for(auto e: envelopes) {
            auto pos = lower_bound(lis.begin(), lis.end(), e[1]);
            
            if(pos == lis.end())  lis.push_back(e[1]);
            else    *pos = e[1];
        }
        return (int)lis.size();
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// DP. O(n^2) time, O(n) space
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty())   return 0;
        sort(envelopes.begin(), envelopes.end(), [&](auto a, auto b) -> bool {
            return a[0] * a[1] < b[0] * b[1];
        });
        
        int n = envelopes.size(), res = 1;
        vector<int> dp(n, 1);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(envelopes[j][0] < envelopes[i][0] and envelopes[j][1] < envelopes[i][1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
