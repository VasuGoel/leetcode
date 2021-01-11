// O(n • logn) time, O(n) space. Binary Search with Rabin-Karp algorithm.
class Solution {
    const int mod = 1e7+7;      // huge prime for avoiding hashing collisions
    vector<int> power;
    
public:
    string longestDupSubstring(string s) {
        int n = s.size(), lo = 0, hi = n, mid;
        string res;
        
        // pre-compute all pow(26, k), 0 < k < n module prime for rolling hash
        power.resize(n);
        for(int i = 0; i < n; i++)  power[i] = !i ? 1 : (power[i-1] * 26) % mod;
        
        // binary search for length of longest substring cuz if duplicate substring of len k is present then substring of len k-1 would of course be present, so search for greater lengths
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            string dup = rabinKarp(s, mid);
            
            if((int)dup.size() > (int)res.size()) {
                res = dup;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        return res;
    }
    
    string rabinKarp(string &s, int len) {
        if(!len)    return "";
        int n = s.size(), hash = 0;
        // map hash values to start index of substrings with that hash value (same hash values for different substrings can occur)
        unordered_map<int, vector<int>> mp;
        
        // compute hash value for first 'len' characters
        for(int i = 0; i < len; i++)
            hash = (hash * 26 + (s[i]-'a')) % mod;
        mp[hash] = {0};     // map this initial hash value with index 0 (means substring of lenght 'len' starting at index 0)
        
        for(int i = len; i < n; i++) {
            // sliding window to maintain current substring's hash
            hash = ((hash - power[len-1] * (s[i-len]-'a')) % mod + mod) % mod;
            hash = (hash * 26 + (s[i]-'a')) % mod;
            
            // if this new hash does not exist in map then store it with the new start index (i-len+1)
            if(!mp.count(hash))     mp[hash] = {i-len+1};
            // if hash already exists in map then for all start indices check if any substrings match with the current window of substr
            else {
                for(int start: mp[hash]) {
                    if(s.substr(start, len) == s.substr(i-len+1, len))
                        return s.substr(start, len);
                }
                // if none matches (happens when different substrings have same hash value) simply map this new start index for current window to this hash value
                mp[hash].push_back(i-len+1);
            }
        }
        return "";      // if no duplicates exist
    }
};
