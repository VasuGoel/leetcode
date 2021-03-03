// O(n) time, O(1) space. Using XOR operation.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        
        for(int i = 0; i < n; i++)
            res ^= (i ^ nums[i]);
        
        return res ^ n;
    }
};


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(n) time, O(1) space. Put elements in correct position.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            while(nums[i] < n and nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }
        
        for(int i = 0; i < n; i++) {
            if(i != nums[i])
                return i;
        }
        return n;
    }
};
