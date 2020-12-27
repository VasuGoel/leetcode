// O(log(min(m, n))) time, O(1) space
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // to perform binary search on smaller array, we fix first as smaller of two
        if(m > n)   return findMedianSortedArrays(nums2, nums1);
        
        // binary search to find partition x and y for first and second array resp.
        int lo = 0, hi = m;
        while(lo <= hi) {
            int px = (lo + hi) / 2;
            int py = (m + n + 1) / 2 - px;
            
            int l1 = px ? nums1[px - 1] : INT_MIN;
            int l2 = py ? nums2[py - 1] : INT_MIN;
            int r1 = (px != m ? nums1[px] : INT_MAX);
            int r2 = (py != n ? nums2[py] : INT_MAX);
            
            if(l1 > r2)     
                hi = px - 1;
            else if(l2 > r1)
                lo = px + 1;
            else {
                if((m + n) & 1)
                    return (double)max(l1, l2);
                else
                    return ((double)max(l1, l2) + min(r1, r2)) / 2;
            }
        }
        return 0;
    }
};


// ----------------------------------------------------------------------------------------––––


// O(m + n) time and space
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0;
        vector<int> res;
        
        // merge two sorted arrays
        while(i < m and j < n) {
            if(nums1[i] < nums2[j])     
                res.push_back(nums1[i++]);
            else    
                res.push_back(nums2[j++]);
        }
        while(i < m)    res.push_back(nums1[i++]);
        while(j < n)    res.push_back(nums2[j++]);
        
        // compute median of merged sorted array
        int len = m + n;
        return len & 1 ? (double)res[len/2] : (double)(res[len/2] + res[len/2-1])/2;
    }
};
