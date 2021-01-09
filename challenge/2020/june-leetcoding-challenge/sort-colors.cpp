// Single pass. O(n) time, O(1) space. Dutch national flag problem.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1, i = 0;
        
        while(i <= r) {
            if(nums[i] == 0)
                swap(nums[l++], nums[i++]);
            else if(nums[i] == 2)
                swap(nums[i], nums[r--]);
            else
                i++;
        }
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Two passes. O(n) time, O(1) space.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> f(3);
        for(int num: nums)  f[num]++;
        
        for(int i = 0, k = 0; i <= 2; i ++) {
            while(f[i]--)   nums[k++] = i;
        }
    }
};
