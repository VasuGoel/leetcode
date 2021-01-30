// O(n) time, O(1) space
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), last = -1, res = 0;
        
        for(int i = 0; i < n; i++) {
            if(seats[i] == 1) {
                if(last == -1)
                    res = i;
                else
                    res = max(res, (i-last)/2);
                last = i;
            }
        }
        return max(res, n-1-last);
    }
};
