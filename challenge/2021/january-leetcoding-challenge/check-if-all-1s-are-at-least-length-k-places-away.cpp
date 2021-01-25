// O(n) time, O(1) space. Two pointer approach.
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        // set 'l' to first occurrence of 1
        while(l < n and !nums[l])   l++;
        
        // check distance between consecutive 1's is at least k
        for(int r = l+1; r < nums.size(); r++) {
            if(nums[r] == 1) {
                if(r-l-1 < k)   return false;
                l = r;
            }
        }
        return true;
    }
};
