// O(logn) time pickIndex() operation, O(n) space, where n = w.size()
class Solution {
    vector<int> prefix;
    
public:
    Solution(vector<int>& w) {
        int sum = 0;
        // create prefix sum array
        for(int x: w)
            sum += x, prefix.push_back(sum);
    }
    
    int pickIndex() {
        int sum = prefix.back();
        // rand() % sum, returns integer between [0, sum-1] and upper_bound of it picks random index with probability of picking index i = w[i] / sum(w)
        return upper_bound(prefix.begin(), prefix.end(), rand() % sum) - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
