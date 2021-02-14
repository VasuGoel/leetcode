// DFS. Check if graph is 2-way colorable.
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,int> m;
        
        for(int i = 0; i < n; i++) {
            if(!m.count(i) and !dfs(graph, i, 0, m))
                return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int>> &graph, int cur, int color, unordered_map<int,int> &m) {
        if(m.count(cur))
            return m[cur] == color;
        
        m[cur] = color;
        for(int neighbor: graph[cur]) {
            if(!dfs(graph, neighbor, color^1, m))
                return false;
        }
        return true;
    }
};
