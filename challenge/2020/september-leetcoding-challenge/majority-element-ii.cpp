// Boyer–Moore majority vote algorithm. O(n) time, O(1) space
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        // find candidate elements
        int a = 0, b = 0, freq1 = 0, freq2 = 0;
        for(int num: nums) {
            if(a == num)
                freq1++;
            else if(b == num)
                freq2++;
            else if(!freq1)
                a = num, freq1 = 1;
            else if(!freq2)
                b = num, freq2 = 1;
            else
                freq1--, freq2--;
        }
        
        // verifying occurence freq
        freq1 = 0, freq2 = 0;
        for(int num: nums) {
            if(num == a)    
                freq1++;
            else if(num == b)
                freq2++;
        }
        
        vector<int> ret;
        if(freq1 > n/3)     ret.push_back(a);
        if(freq2 > n/3)     ret.push_back(b);
        return ret;
    }
};

/*

There can only be at most 2 elements with more than n/3 occurences in an array of size n.
We can easily find 2 candidates using Boyer–Moore majority vote algorithm and then verify if they do actually
occur more than n/3 times.

*/
