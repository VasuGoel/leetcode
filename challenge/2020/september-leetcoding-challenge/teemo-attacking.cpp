// O(n) time, O(1) space
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size(), res = 0;
        int prevL = -1, prevR = -1, curL = 0, curR = 0, overlap = 0;
        
        for(int i = 0; i < n; i++) {
            curL = timeSeries[i], curR = curL + duration - 1;
            
            if(curL <= prevR)
                overlap = prevR - curL + 1;
            else
                overlap = 0;
                
            res += duration - overlap;
            
            prevL = curL, prevR = curR;
        }
        return res;
    }
};
