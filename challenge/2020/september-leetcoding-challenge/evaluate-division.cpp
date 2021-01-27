// BFS. Time complexity, if there are m queries, q equations and n distinct values, it will be O(m•(q+n)) ~ O(m • n^2) as q can grow to the order of n^2
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        
        // build weighted directed graph
        for(int i = 0; i < equations.size(); i++) {
            auto eq = equations[i];
            graph[eq[0]].push_back({eq[1], values[i]});
            graph[eq[1]].push_back({eq[0], (double)1/values[i]});
        }
        
        vector<double> ret;
        // perform bfs on valid query equations
        for(auto q: queries) {
            if(!graph.count(q[0]) or !graph.count(q[1]))
                ret.push_back(-1);
            else
                ret.push_back(bfs(graph, q[0], q[1]));
        }
        return ret;
    }
    
    double bfs(unordered_map<string, vector<pair<string, double>>> &graph, string &src, string &dst) {
        queue<pair<string,double>> q;
        q.push({src, 1});
        
        unordered_set<string> seen;
        seen.insert(src);
        
        while(!q.empty()) {
            auto it = q.front(); q.pop();
            string cur = it.first;
            double d = it.second;
            
            if(cur == dst)  return d;
            
            for(auto e: graph[cur]) {
                string neighbor = e.first;
                double w = e.second;
                
                if(!seen.count(neighbor)) {
                    q.push({neighbor, d * w});
                    seen.insert(neighbor);
                }
            }
        }
        return -1;
    }
};

/*

Although this looks like a math problem, we can easily model it with graph.

For example:
Given:
a/b = 2.0, b/c = 3.0
We can build a directed graph:
a -- 2.0 --> b -- 3.0 --> c
If we were asked to find a/c, we have:
a/c = a/b * b/c = 2.0 * 3.0
In the graph, it is the product of costs of edges.

Do notice that, 2 edges need to added into the graph with one given equation,
because with a/b we also get result of b/a, which is the reciprocal of a/b.
so the previous example also gives edges:
c -- 0.333 --> b -- 0.5 --> a

Now we know how to model this problem, what we need to do is simply build the
graph with given equations, and traverse the graph, either DFS or BFS, to find a path
for a given query, and the result is the product of costs of edges on the path.

*/
