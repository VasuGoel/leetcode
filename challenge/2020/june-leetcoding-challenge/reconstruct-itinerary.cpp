// Eulerian Path
class Solution {
    // we use multiset instead of set since their can be more than one flight from A to B
    unordered_map<string, multiset<string>> graph;
    deque<string> q;    // stores final itinerary
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(vector<string> t: tickets)
            graph[t[0]].insert(t[1]);
        
        dfs("JFK");
        return {q.begin(), q.end()};
    }
    
    void dfs(string cur) {
        // while there are still flights from current airport
        while(!graph[cur].empty()) {
            // get the next lexicographically smallest airport
            auto it = graph[cur].begin();
            string next = *it;
            // remove it from map of current airport
            graph[cur].erase(it);
            // recursively call dfs on next airport
            dfs(next);
        }
        // when current airport has no more outgoing edges add it the start of itinerary
        q.push_front(cur);
    }
};

/*

Its required that we use all tickets (once and only once), so it can be thought of as finding a Eulerian path (a path where we visit each edge only once but may visit a vertex several times) in this directed graph of flights.
If there are multiple flights from airport A, then we're supposed to pick one such that final itinerary has the smallest lexical order when read as a single string, for ex: the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"], but we've to make sure all tickets are used (or all edges are visited). 

We can accomplish this above task by using a multiset where each string is sorted lexicographically automatically and we can store same airport any number of times (since there can be multiple flights from airport A to B).

To find eulerian path, we can just use usual DFS.First keep going forward until you get stuck. That's a good main path already. Remaining tickets form cycles which are found on the way back and get merged into that main path. By writing down the path backwards when retreating from recursion, merging the cycles into the main path is easy.

Consider this graph: https://www.stefan-pochmann.info/misc/reconstruct-itinerary.png

From JFK we first visit JFK -> A -> C -> D -> A. There we're stuck, so we write down A as the end of the route and retreat back to D. There we see the unused ticket to B and follow it: D -> B -> C -> JFK -> D. Then we're stuck again, retreat and write down the airports while doing so: Write down D before the already written A, then JFK before the D, etc. When we're back from our cycle at D, the written route is D -> B -> C -> JFK -> D -> A. Then we retreat further along the original path, prepending C, A and finally JFK to the route, ending up with the route JFK -> A -> C -> D -> B -> C -> JFK -> D -> A.

*/
