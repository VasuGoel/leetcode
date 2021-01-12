// O(n^2) time, O(n) space
class Solution {
public:
    string getPermutation(int n, int k) {
        string num, res;
        vector<int> fact(n+1, 1);
        
        for(int i = 1; i <= n; i++) {
            num += to_string(i);        // build numeric string from 1..n
            fact[i] = fact[i-1] * i;    // pre-compute factorials
        }
        
        // to ease calculation for finding index i
        k--;
        while((n = num.size())) {
            // find index of next number to build required permutation sequence
            int i = k / fact[n-1];
            res += num[i];

            k = k - i * fact[n-1];  // remove number of skipped permutations
            num.erase(i, 1);        // erase operation increase time complexity from linear to quadratic
        }
        return res;
    }
};
