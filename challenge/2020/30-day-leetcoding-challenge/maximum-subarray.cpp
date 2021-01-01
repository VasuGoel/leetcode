// O(n) time, O(1) space
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        for(int num: nums) {
            sum += num;
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res;
    }
};
