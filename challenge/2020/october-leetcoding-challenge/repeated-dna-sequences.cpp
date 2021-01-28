// O(n) time and space
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10)   return {};
        unordered_set<string> ret, st;
        
        for(int i = 0; i <= s.size()-10; i++) {
            string seq = s.substr(i, 10);
            if(!st.count(seq))
                st.insert(seq);
            else
                ret.insert(seq);
        }
        return {ret.begin(), ret.end()};
    }
};
