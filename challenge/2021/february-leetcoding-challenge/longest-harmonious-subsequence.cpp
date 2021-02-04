// O(n) time and space
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num: nums)  freq[num]++;
        
        int res = 0;
        for(auto &e: freq) {
            if(freq.count(e.first-1))
                res = max(res, freq[e.first] + freq[e.first-1]);
        }
        return res;
    }
};
