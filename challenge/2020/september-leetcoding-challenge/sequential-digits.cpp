// BFS
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i = 1; i <= 9; i++)
            q.push(i);
        
        vector<int> ret;
        while(!q.empty()) {
            for(int i = 0; i < q.size(); i++) {
                auto cur = q.front(); q.pop();

                if(cur >= low and cur <= high)
                    ret.push_back(cur);
                
                if(cur % 10 < 9)
                    q.push(cur*10+cur%10+1);
            }
        }
        return ret;
    }
};


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// DFS to generate all possible sequential digits (exhausts entire search space)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // DFS would return unsorted sequence. Ex: [1000, 13000] would return [1234,12345,2345,3456,4567,5678,6789]
        set<int> ret;   
        
        for(int i = 1; i <= 9; i++)
            dfs(i, low, high, ret);
        
        return {ret.begin(), ret.end()};
    }
    
    void dfs(int cur, int &low, int &high, set<int> &ret) {
        if(cur >= low and cur <= high)
            ret.insert(cur);
        
        if(cur % 10 < 9)
            dfs(cur*10+cur%10+1, low, high, ret);
    }
};
