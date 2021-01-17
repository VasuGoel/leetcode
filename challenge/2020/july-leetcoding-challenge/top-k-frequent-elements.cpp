// O(n•logn) time, O(n) space
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num: nums)  
            freq[num]++;
        
        auto comp = [&](int &a, int &b) { return freq[a] < freq[b]; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        
        for(auto f: freq)
            pq.push(f.first);
        
        vector<int> ret;
        while(k--) {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};
