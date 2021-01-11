// O(logn) time, O(1) space. Binary search.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), lo = 0, hi = n-1, mid;
        
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            if(citations[mid] == n-mid)
                return n-mid;
            else if(citations[mid] < n-mid)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return n-lo;
    }
};
