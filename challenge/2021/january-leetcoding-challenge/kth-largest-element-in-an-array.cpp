// O(nlogn) time, O(n) space. O(n) to build heap and in worst-case we remove k = n elements from heap.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q (nums.begin(), nums.end());
        
        while(--k)
            q.pop();
        
        return q.top();
    }
};
