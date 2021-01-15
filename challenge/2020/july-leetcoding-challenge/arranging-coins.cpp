// O(logn) time, O(1) space. Binary Search.
class Solution {
public:
    int arrangeCoins(int n) {
        int lo = 0, hi = n, mid;
        
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            long sum = (long)mid * (mid + 1) / 2;
            if(sum == n)    return mid;
            else if(sum < n)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return hi;
    }
};
