// O(3000) ~ O(1) time ping() operation, using monotonic queue
class RecentCounter {
    queue<int> q;
    
public:
    int ping(int t) {
        q.push(t);
        // since each call to ping() guarantees increasing value of t, for each t remove time older than t-3000 from monotonic queue
        while(!q.empty() and q.front() < t-3000)
            q.pop();
        return q.size();
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(logn) time ping() operation, using binary search
class RecentCounter {
    vector<int> times;
    
public:
    int ping(int t) {
        times.push_back(t);
        int pos = lower_bound(times.begin(), times.end(), t-3000) - times.begin();
        return times.size()-pos;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
