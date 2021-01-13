// O(n) time, O(1) space. Two pointer and Greedy.
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int l = 0, r = people.size()-1, boats = 0;
        
        while(l < r) {
            if(people[l] + people[r] > limit)
                r--;
            else
                l++, r--;
            
            boats++;
        }
        return l == r ? ++boats : boats;
    }
};
