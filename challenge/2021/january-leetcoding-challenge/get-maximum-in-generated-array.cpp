// O(n) time and space. Generate the required array.
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(!n)  return 0;

        int res = 1;
        vector<int> nums(n+1);
        nums[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            if(i & 1)
                nums[i] = nums[(i-1)/2] + nums[(i+1)/2];
            else
                nums[i] = nums[i/2];
            
            res = max(res, nums[i]);
        }
        return res;
    }
};
