// O(n) time and space. Similar idea as Two Sum problem.
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ops = 0;
        unordered_multiset<int> s;
        
        for(int num: nums) {
            if(s.count(k - num)) {
                ops++;
                s.erase(s.find(k - num));
            }
            else
                s.insert(num);
        }
        return ops;
    }
};
