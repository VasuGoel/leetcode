// O(n) time and space
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        
        for(int i = 0; i < num.size(); i++) {
            // maintain non-decreasing string
            while(k and !res.empty() and num[i] < res.back())   
                k--, res.pop_back();
            
            // add digit to 'res' but skip if its leading zero
            if(num[i] != '0' or (num[i] == '0' and !res.empty()))
                res += num[i];
        }
        
        // for cases like num = "123", k = 1
        while(k-- and !res.empty())  res.pop_back();
        return res.empty() ? "0" : res;
    }
};
