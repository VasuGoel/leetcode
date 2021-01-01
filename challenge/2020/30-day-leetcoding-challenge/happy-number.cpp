// O(1) time and space
class Solution {
public:
    bool isHappy(int n) {
        for(int i = 0; i < 20; i++) {
            if((n = next(n)) == 1)    return true;
        }
        return false;
    }
    
    int next(int n) {
        int res = 0;
        while(n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};
