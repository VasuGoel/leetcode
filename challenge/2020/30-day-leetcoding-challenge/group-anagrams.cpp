// O(n • sorting each str) time, where n = strs length, and each str (in strs) length <= 100
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> mp;
        
        for(auto str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }

        for(auto group: mp)     ret.push_back(group.second);
        return ret;
    }
};
