// O(log(n/2)) time, O(1) space
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)    return true;
        int lo = 1, hi = num / 2, mid;
        
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            if((long long) mid * mid == num)    
                return true;
            else if((long long) mid * mid < num)    
                lo = mid+1;
            else    
                hi = mid-1;
        }
        return false;
    }
};
