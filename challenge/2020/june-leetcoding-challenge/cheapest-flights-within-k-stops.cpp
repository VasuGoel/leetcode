// BFS
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int res = INT_MAX;
        vector<vector<int>> graph(n), weights(n, vector<int>(n));
        
        for(vector<int> f: flights) {
            graph[f[0]].push_back(f[1]);
            weights[f[0]][f[1]] = f[2];
        }
        
        // queue to store vector {current node, cost to travel, stops utilized}
        queue<vector<int>> q;
        q.push({src, 0, 0});
        
        while(!q.empty()) {
            auto e = q.front(); q.pop();
            int cur = e[0], cost = e[1], stops = e[2];
            
            for(int neighbor: graph[cur]) {
                int new_cost = cost + weights[cur][neighbor];
                
                if(neighbor == dst)
                    res = min(res, new_cost);
                else if(new_cost < res and stops + 1 <= K)
                    q.push({neighbor, new_cost, stops + 1});
            }
        }
        return res != INT_MAX ? res : -1;
    }
};
