// O(n•k) time, O(2^k) space. Store all k bit substrings in hashset and check if it equals 2^k (all possible k bit numbers)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> unique;
        
        for(int i = k; i <= s.size() and (int)unique.size() < (1 << k); i++) {
            unique.insert(bitset<32>(s.substr(i-k, k)).to_ulong());
        }
        return unique.size() == (1 << k);
    }
};
