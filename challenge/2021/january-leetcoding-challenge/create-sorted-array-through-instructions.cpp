// Fenwick Tree (or Binary Indexed Tree). O(n • logm) time, O(m) space, where m = range of instructions[i].
class Solution {
    const int m = 1e5+1;
    vector<int> b;
    
public:
    int createSortedArray(vector<int>& instructions) {
        b.resize(m);
        int n = instructions.size(), cost = 0, mod = 1e9+7;
        
        for(int i = 0; i < n; i++) {
            cost = (cost + min(get(instructions[i]-1), i - get(instructions[i]))) % mod;
            increment(instructions[i]);
        }
        return cost;
    }
    
    int get(int x) {
        int res = 0;
        while(x > 0) {
            res += b[x];
            x -= (x & -x);
        }
        return res;
    }
    
    void increment(int x) {
        while(x < m) {
            b[x]++;
            x += (x & -x);
        }
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(n • logn) time, O(n) space. [TLE]
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int cost = 0;
        multiset<int> s;
        
        for(int num: instructions) {
            int lb = distance(s.begin(), s.lower_bound(num));
            int ub = distance(s.begin(), s.upper_bound(num));
            
            cost = (cost + min(lb, (int)s.size() - ub)) % (int)(1e9+7);
            s.insert(num);
        }
        return cost;
    }
};
