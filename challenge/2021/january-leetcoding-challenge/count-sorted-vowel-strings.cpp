// O(n • k) time and space, where n = length of required strings, k = 5 (no. of vowels)
class Solution {
public:
    int countVowelStrings(int n) {
        int k = 5;
        // dp[i][j] means count of sorted vowel strings of length 'i' starting with vowel 'j'
        vector<vector<int>> dp(n+1, vector<int>(k));
        
        for(int i = 1; i <= n; i++) {
            for(int j = k-1; j >= 0; j--)
                dp[i][j] =  (j == k-1 ? 1 : dp[i][j+1] + dp[i-1][j]);
        }
        return accumulate(dp[n].begin(), dp[n].end(), 0);
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(n • k) time, O(k) space, where n = length of required strings, k = 5 (no. of vowels)
class Solution {
public:
    int countVowelStrings(int n) {
        int k = 5;
        vector<int> dp(k, 1);
        
        for(int i = 2; i <= n; i++) {
            for(int j = k-1; j >= 0; j--)
                dp[j] += (j < k-1 ? dp[j+1] : 0);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Extras: Generate all possible lexicographically sorted vowel strings. DFS/Backtracking.
class Solution {
    const string vowels = "aeiou";
    
public:
    int countVowelStrings(int n) {
        vector<string> ret;
        dfs(n, 0, string()={}, ret);
        return ret.size();
    }
    
    void dfs(int n, int pos, string &path, vector<string> &ret) {
        if(!n) {
            ret.push_back(path);
            return;
        }
        
        for(int i = pos; i < vowels.size(); i++) {
            path += vowels[i];
            dfs(n-1, i, path, ret);
            path.pop_back();
        }
    }
};
