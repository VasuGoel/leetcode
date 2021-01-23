// O(m + n) time and space
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream s1(version1), s2(version2);
        string a, b;
        
        while(s1.good() and s2.good()) {
            getline(s1, a, '.');
            getline(s2, b, '.');
            
            int x = stoi(a), y = stoi(b);
            if(x != y)
                return x > y ? 1 : -1;
        }
        while(getline(s1, a, '.'))  if(stoi(a))     return 1;
        while(getline(s2, b, '.'))  if(stoi(b))     return -1;
        return 0;
    }
};
