// DP. O(n^2) time, O(n) space.
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long res = 0, mod = 1e9+7;
        unordered_map<int,long> dp;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0)
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i]/arr[j]]) % mod;
            }
            res = (res + dp[arr[i]]) % mod;
        }
        return res;
    }
};

/*

• Sort the array (it's bottom-up DP and only smaller values can be leaf nodes)
• Use hashmap to store number of required binary trees formed by arr[i] as root
• If arr[j] is a divisor of arr[i], where 0 ≤ j < i, then dp[arr[i]] += (dp[arr[j]] * dp[arr[i] / arr[j]]),
  since arr[j] can be root of arr[i]'s left subtree and arr[i]/arr[j] can be root of its right subtree,
  and there are (dp[arr[j]] * dp[arr[i] / arr[j]]) such binary trees.

*/
