// O(1) time and space. Find smaller difference between angle subtended by hour and minutes hand.
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour % 12) * 30 + ((double)minutes / 60) * 30;
        double m = minutes * 6;
        
        double res = abs(h - m);
        return (res < 180) ? res : (360 - res);
    }
};
