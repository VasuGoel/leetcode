// O(n) time, O(1) space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        for(int i = 0, cycles = 0; cycles < n; i++) {
            int cur = i, x = nums[i];
            do {
                cur = (cur + k) % n;
                swap(nums[cur], x);
                cycles++;
            } while(cur != i);
        }
    }
};
