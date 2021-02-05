// O(n) time and space
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> ret;
        istringstream ss(path);
        string dir;
        
        while(getline(ss, dir, '/')) {
            if(dir.empty() or dir == ".")
                continue;
            else if(dir == "..") {
                if(!ret.empty())    ret.pop_back();
            }
            else
                ret.push_back(dir);
        }
        
        string res = "/";
        for(int i = 0; i < ret.size(); i++)
            res += ret[i] + (i != ret.size()-1 ? "/" : "");
        
        return res;
    }
};
