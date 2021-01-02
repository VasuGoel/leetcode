// O(n) time and space
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, res = 0;
        unordered_map<int,int> mp {{0, -1}};
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] ? 1 : -1;
            
            if(!mp.count(sum))  mp[sum] = i;
            else    res = max(res, i - mp[sum]);
        }
        return res;
    }
};
