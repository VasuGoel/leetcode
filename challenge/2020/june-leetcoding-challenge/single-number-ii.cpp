// O(n) time, O(1) space. Bit manipulation.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        
        for(int i = 0; i < 32; i++) {
            // count no. of set i'th bit
            int set = 0;
            for(int num: nums)  
                if(num & (1 << i))  set++;
            
            // resultant single number would have i'th bit set if, (no. of set i'th bit) % 3 == 1
            res |= (set % 3) << i;
        }
        return res;
    }
};
