// DFS
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        vector<vector<int>> graph(N+1);
        
        // model dislike pairs into graph, where edge between 2 people (nodes) denotes disliking
        for(vector<int> d: dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        
        // check if this dislike graph is 2-way colorable, means it has possible bipartition
        vector<bool> seen(N+1), colors(N+1);
        for(int i = 1; i <= N; i++) {
            if(!seen[i] and !dfs(graph, i, seen, colors, 0))
                return false;
        }
        return true;
    }
    
    // return true if graph is 2-way colorable by coloring adjacent nodes with alternating colors
    bool dfs(vector<vector<int>> &graph, int i, vector<bool> &seen, vector<bool> &colors, int c) {
        // if node 'i' is already colored, return true if its color matches current dfs call color 'c'
        if(seen[i])     return colors[i] == c;
        
        // mark node 'i' as seen and color it 'c'
        seen[i] = 1, colors[i] = c;
        
        for(int neighbor: graph[i]) {
            // if remaining graph is not 2-way colorable
            if(!dfs(graph, neighbor, seen, colors, c^1))
                return false;
        }
        return true;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// BFS
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        vector<vector<int>> graph(N+1);
        
        // model dislike pairs into graph, where edge between 2 people (nodes) denotes disliking
        for(vector<int> d: dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        
        // check if this dislike graph is 2-way colorable, means it has possible bipartition
        vector<bool> seen(N+1), colors(N+1);
        for(int i = 1; i <= N; i++) {
            if(!seen[i] and !bfs(graph, i, seen, colors))
                return false;
        }
        return true;
    }
    
    // return true if graph is 2-way colorable by coloring adjacent nodes with alternating colors
    bool bfs(vector<vector<int>> &graph, int i, vector<bool> &seen, vector<bool> &colors) {
        queue<pair<int, bool>> q;
        q.push({i, 0});
        seen[i] = 1, colors[i] = 0;
        
        while(!q.empty()) {
            int cur = q.front().first, color = q.front().second; q.pop();
            
            for(int neighbor: graph[cur]) {
                if(seen[neighbor]) {
                    if(colors[neighbor] != color^1)
                        return false;
                }
                else {
                    q.push({neighbor, color^1});
                    seen[neighbor] = 1, colors[neighbor] = color^1;
                }
            }
        }
        return true;
    }
};
