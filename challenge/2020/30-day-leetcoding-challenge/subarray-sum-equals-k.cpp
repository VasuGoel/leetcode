// O(n) time and space. Hashmap and prefix-sum.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp {{0, 1}};
        int sum = 0, res = 0;
        
        for(int num: nums) {
            sum += num;
            
            if(mp.count(sum - k))   res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};
