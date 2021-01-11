// O(n) time and space
class Solution {
public:
    string validIPAddress(string IP) {
        if(isIPv4(IP))  return "IPv4";
        if(isIPv6(IP))  return "IPv6";
        return "Neither";
    }
    
    bool isIPv4(string s) {
        int parts = 0;
        string num;
        istringstream ss(s);
        
        while(ss.good()) {
            getline(ss, num, '.');
            parts++;
            try {
                int n = stoi(num);
                if(to_string(n) != num or n < 0 or n > 255)
                    return false;
            }
            catch(exception e) {
                return false;
            }
        }
        return parts == 4;
    }
    
    bool isIPv6(string s) {
        int parts = 0;
        string num;
        istringstream ss(s);
        
        while(ss.good()) {
            getline(ss, num, ':');
            parts++;
            if(num.empty() or num.size() > 4 or !isHexaDecimal(num))
                return false;
        }
        return parts == 8;
    }
    
    bool isHexaDecimal(string s) {
        for(char c: s)  if(!isxdigit(c))    return false;
        return true;
    }
};
