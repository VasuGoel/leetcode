// O(n•logn) time, O(n) space
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ret;
        for(int num: nums)
            ret.push_back(to_string(num));
        
        sort(ret.begin(), ret.end(), [&](string &a, string &b) -> bool {
            return a + b > b + a;
        });
        
        string res;
        for(string s: ret)
            res += s;
        
        return res[0] == '0' ? "0" : res;
    }
};
