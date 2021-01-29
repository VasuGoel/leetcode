// O(n) time and space. Stack-based approach.
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;    // simulates stack
    
        for(int cur: asteroids) {
            bool destroyed = false;
            
            while(!ret.empty() and ret.back() > 0 and cur < 0) {
                if(ret.back() >= -cur) {
                    if(ret.back() == -cur)  ret.pop_back();
                    destroyed = true;
                    break;
                }
                else
                    ret.pop_back();
            }
            
            if(!destroyed)  ret.push_back(cur);
        }
        return ret;
    }
};
