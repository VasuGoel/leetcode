// topological sort
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph (numCourses);
        vector<int> indegrees (numCourses);
        
        for(vector<int> pre: prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegrees[pre[0]]++;
        }
        
        int count = 0;
        queue<int> q;
        for(int i = 0; i < indegrees.size(); i++)
            if(!indegrees[i])   q.push(i);
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            count++;
            
            for(int neighbor: graph[cur]) {
                if(--indegrees[neighbor] == 0)  q.push(neighbor);
            }
        }
        return count == numCourses;
    }
};
