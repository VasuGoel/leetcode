// Topological sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph (numCourses);
        vector<int> indegrees (numCourses);
        
        for(vector<int> &p: prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegrees[p[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(!indegrees[i])   q.push(i);
        
        vector<int> ret;
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            ret.push_back(cur);
            
            for(int neighbor: graph[cur])
                if(!--indegrees[neighbor])  q.push(neighbor);
        }
        // if no. of courses scheduled ≠ numCourses, means no possible ordering, hence return empty vector
        return (ret.size() == numCourses) ? ret : vector<int>();
    }
};
