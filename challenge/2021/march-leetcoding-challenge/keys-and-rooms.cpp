// Typical DFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        return dfs(rooms, 0, unordered_set<int>()={});
    }
    
    bool dfs(vector<vector<int>> &rooms, int cur, unordered_set<int> &seen) {
        seen.insert(cur);
        
        for(int key: rooms[cur]) {
            if(!seen.count(key))
                dfs(rooms, key, seen);
        }
        return seen.size() == rooms.size();
    }
};
