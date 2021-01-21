// O(n) time and space
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        k = n-k;
        
        vector<int> ret;
        for(int num: nums) {
            while(k and !ret.empty() and num < ret.back())
                k--, ret.pop_back();
            
            ret.push_back(num);
        }
        while(k-- and !ret.empty())  ret.pop_back();
        return ret;
    }
};

/*

Intuition:
• Similar to problem Remove K Digits, to form lexicographically smallest subsequence
• We can easily modify this problem by observing we only need to remove (n-k) elements from nums, 
  where n = length of nums, k = size of required competitive subsequence, to get desired subsequence

*/
