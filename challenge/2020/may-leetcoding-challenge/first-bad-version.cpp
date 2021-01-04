// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// O(logn) time. Typical binary search.
class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n, mid;
        
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            if(isBadVersion(mid))   
                hi = mid-1;
            else    
                lo = mid+1;
        }
        return lo;
    }
};
