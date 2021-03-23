// O(n^2) time
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int res = 0, mod = 1e9+7, n = arr.size();
        unordered_map<int,int> freq;
        
        for(int i = 0; i < n; i++) {
            res = (res + freq[target - arr[i]]) % mod;
            
            for(int j = 0; j < i; j++)
                freq[arr[i] + arr[j]]++;
        }
        return res;
    }
};
