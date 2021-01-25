// O(n) time, O(1) space 
class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<pair<int,int>> dirs {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int x = 0, y = 0, d = 0;
        
        for(char c: instructions) {
            if(c == 'L')
                d = (d + 1) % 4;
            else if(c == 'R')
                d = (d + 3) % 4;
            else
                x += dirs[d].first, y += dirs[d].second;
        }
        return (!x and !y) or d > 0;
    }
};

/*

• Intuition -
Starting at the origin and face north (0,1), after one sequence of instructions,

• if robot returns to the origin, it is obviously in an circle
• if chopper finishes with face not towards north, it will get back to the initial status in another one or three sequences


• Explanation - 
(x,y) is the location of robot
d[i] is the direction it is facing
i = (i + 1) % 4 will turn left
i = (i + 3) % 4 will turn right
Check the final status after instructions

*/
