// O(n) time and space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(target - nums[i]))  return {mp[target - nums[i]], i};
            
            mp[nums[i]] = i;
        }
        throw runtime_error("No possible pair.");
    }
};


// ------------------------------------------------------------------------------------------–––––


// O(n^2) time, O(1) space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        throw runtime_error("No possible pair.");
    }
};
