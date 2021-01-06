// O(n) time, O(1) space. Keep track of missing positive integers while traversing arr.
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0, end, missing;
        
        for(int i = 0; i < arr.size(); i++) {
            end = arr[i];
            // if there are missing integers between consecutive elements
            if(end - start > 1) {
                missing = end - start - 1;      // find no. of missing integers

                if(k <= missing)    return start + k;
                else    k -= missing;
            }
            start = end;
        }
        return arr.back() + k;
    }
};


// ------------------------------------------------------------------------------------------–––


// O(logn) time, O(1) space. Binary search.
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size(), mid;
        
        while(l < r) {
            mid = (l + r) / 2;
            
            if(arr[mid] - mid - 1 < k)  
                l = mid + 1;
            else
                r = mid;
        }
        return l + k;
    }
};
