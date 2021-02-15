// O(n•logn) time, O(n) space
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        set<pair<int,int>> s;
        
        for(int i = 0; i < n; i++)
            s.insert({countOnes(mat[i]), i});
        
        vector<int> ret;
        for(auto it = s.begin(); k ; it++, k--)
            ret.push_back(it->second);
        
        return ret;
    }
    
    // binary search to count number of 1s
    int countOnes(vector<int> &nums) {
        int lo = 0, hi = nums.size()-1, mid;
        
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            
            if(nums[mid] == 1)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return lo;
    }
};
