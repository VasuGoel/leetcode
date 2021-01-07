// O(n) time and space
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp {{0, -1}};
        int sum = 0, res = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] ? 1 : -1;
            
            if(mp.count(sum))   
                res = max(res, i - mp[sum]);
            else    
                mp[sum] = i;
        }
        return res;
    }
};
