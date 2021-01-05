// O(N) time and space
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<bool> trustSomeone(N+1);
        vector<int> trustCount(N+1);
        
        for(auto t: trust) {
            trustSomeone[t[0]] = 1;
            trustCount[t[1]]++;
        }
        
        // iterate over each person 'i'
        for(int i = 1; i <= N; i++) {
            // if person 'i' does not trust anyone and their trust count equals N-1, they are the town judge
            if(!trustSomeone[i] and trustCount[i] == N-1)
                return i;
        }
        return -1;
    }
};
