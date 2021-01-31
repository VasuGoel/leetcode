// O(n^2) time, O(n) space
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxlen = 1, res = 0;
        
        vector<int> len(n,1), count(n,1);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(len[i] == len[j]+1)
                        count[i] += count[j];
                    
                    if(len[i] < len[j]+1) {
                        len[i] = len[j]+1;
                        count[i] = count[j];
                    }
                }
            }

            if(len[i] == maxlen)    
                res += count[i];
            else if(len[i] > maxlen) {
                maxlen = len[i];
                res = count[i];
            }
        }
        return res;
    }
};

/*

len[i]   : length of longest increasing subsequence ending at nums[i]
count[i] : number of longest increasing subsequences ending at nums[i]

Ex: nums  = [1,3,5,4,7]
    dp    = [1 2 3 3 4]
    count = [1 1 1 1 2]

*/
