// Boyer-Moore majority voting algorithm. O(n) time, O(1) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, freq = 0;
        
        for(int num: nums) {
            if(freq == 0)   
                candidate = num, freq = 1;
            else    
                freq += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};


// ----------------------------------------------------------------------------------------------------


// O(n) time, O(1) space. Bit-manipulation. Bits in majority element are just majority bits among nums
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), res = 0;
        
        for(int i = 0; i < 32; i++) {
            int freq = 0;
            for(int num: nums)  if(num & (1 << i))  freq++;
            
            res |= (freq > n/2) << i;
        }
        return res;
    }
};


// ----------------------------------------------------------------------------------------------------


// O(n) time and space. Using hashmap to maintain count.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num: nums)  mp[num]++;
        
        for(int num: nums) {
            if(mp[num] > nums.size()/2)  return num;
        }
        return -1;
    }
};
