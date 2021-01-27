// O(n) time and space
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num: nums)
            mp[num]++;
        
        int res = 0;
        for(auto e: mp) {
            if(mp.count(e.first + k)) {
                if(k or (!k and e.second > 1))
                    res++;
            }
        }
        return res;
    }
};
