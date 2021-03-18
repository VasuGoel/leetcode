// O(n) time, O(1) space
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), up = 1, down = 1, diff;

        for(int i = 1; i < n; i++) {
            diff = nums[i] - nums[i-1];

            if(diff > 0)    
                up = down + 1;
            else if(diff < 0)   
                down = up + 1;
        }
        return max(up, down);
    }
};

/*

For each element, there are 3 possibilities,
- up position or nums[i-1] < nums[i]
- down position or nums[i-1] > nums[i]
- equals or nums[i-1] == nums[i]

We can use two arrays 'up' and 'down' to record the max wiggle seq length so far at index i,
- For up position, the element before it must be in down position, so up[i] = down[i-1] + 1; down[i] keeps the same with before.
- For down position, the element before it must be a up position, so down[i] = up[i-1] + 1; up[i] keeps the same with before.
- For equals position, that means it will not change anything becasue it didn't wiggle at all. so both down[i] and up[i] keep the same.

Above is the constant space version of this idea.

*/


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(n) time, O(n) space
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)   return n;
        
        vector<int> diffs;
        for(int i = 1; i < n; i++) {
            int diff = nums[i] - nums[i-1];
            
            if(diff > 0)   
                diffs.push_back(1);
            else if(diff < 0)  
                diffs.push_back(0);
        }
        if(diffs.empty())    return 1;
        
        int res = 1, s = diffs[0];
        for(int diff: diffs)
            if(diff == s)   res++, s ^= 1;
            
        return res;
    }
};
