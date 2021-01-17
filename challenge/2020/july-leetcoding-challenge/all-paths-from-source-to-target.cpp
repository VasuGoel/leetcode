// DFS
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ret;
        dfs(graph, 0, vector<int>() = {0}, ret);
        return ret;
    }
    
    void dfs(vector<vector<int>> &graph, int cur, vector<int> &path, vector<vector<int>> &ret) {
        if(cur == graph.size()-1) {
            ret.push_back(path);
            return;
        }
        
        for(int neighbor: graph[cur]) {
            path.push_back(neighbor);
            dfs(graph, neighbor, path, ret);
            path.pop_back();
        }
    }
};
