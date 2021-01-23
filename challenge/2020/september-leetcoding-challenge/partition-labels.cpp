// O(n) time, O(1) space. Two-pointers.
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1), ret;
        
        for(int i = 0; i < s.size(); i++)   
            last[s[i]-'a'] = i;
        
        int l = 0, r = 0;
        for(int i = 0; i < s.size(); i++) {
            r = max(r, last[s[i]-'a']);
            
            if(i == r) {
                ret.push_back(r-l+1);
                l = r+1;
            }
        }
        return ret;
    }
};
