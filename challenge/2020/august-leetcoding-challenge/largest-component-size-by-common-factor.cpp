// Union-Find (Disjoint Sets) data structure (with path compression optimization)
class UnionFindSet {
    vector<int> parents;

public:
    UnionFindSet(int n): parents(n) {
        iota(parents.begin(), parents.end(), 0);
    }
    
    void Union(int u, int v) {
        parents[Find(u)] = parents[Find(v)];
    }
    
    int Find(int x) {
        if(parents[x] != x)     parents[x] = Find(parents[x]);
        return parents[x];
    }
};

// O(n • sqrt(W)) time, O(W) space, where n = length of A, and W = max number in A
class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int maxval = *max_element(A.begin(), A.end());
        UnionFindSet s(maxval+1);
        
        // union each num in A with its factors
        for(int num: A) {
            for(int i = 2; i*i <= num; i++) {
                if(num % i == 0) {
                    s.Union(num, i);
                    s.Union(num, num/i);
                }
            }
        }
        
        // find most frequent parent (since numbers that belong to same component have same parent)
        int res = 0;
        unordered_map<int,int> freq;
        for(int num: A)
            res = max(res, ++freq[s.Find(num)]);
        return res;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Draw graph and count size of connected components. O(n^2) time, O(n) space. [TLE]
class Solution {
    unordered_map<int, unordered_set<int>> graph;
    unordered_set<int> seen;
    
public:
    int largestComponentSize(vector<int>& A) {
        int n = A.size(), res = 0;
        
        // draw graph with nodes as nums in A, and edge between two numbers if their gcd > 1 (have common factor other than 1)
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(__gcd(A[i], A[j]) > 1)   graph[A[i]].insert(A[j]), graph[A[j]].insert(A[i]);
            }
        }
        
        // find max size among all connected components
        for(int i = 0; i < n; i++) {
            if(!seen.count(A[i])) {
                int len = 0;
                dfs(A[i], len);
                res = max(res, len);
            }
        }
        return res;
    }
    
    void dfs(int cur, int &len) {
        seen.insert(cur);
        len++;
        
        for(int neighbor: adjlist[cur]) {
            if(!seen.count(neighbor))   dfs(neighbor, len);
        }
    }
};
