class Solution {
    const double PI = 3.14159265358979732384626433832795;
    double radius, x_center, y_center;
    
public:
    Solution(double radius, double x_center, double y_center): radius(radius), x_center(x_center), y_center(y_center) {}
    
    vector<double> randPoint() {
        double theta = 2 * PI * ((double)rand() / RAND_MAX);
        double r = sqrt((double)rand() / RAND_MAX);     // r is the distance of the random point to the origin (in the unit circle). Since Probability(r < A) = A^2 (The inner circle with radius A), so we can simply take sqrt(A) to get r.
        
        double x = x_center + (r * radius * cos(theta));
        double y = y_center + (r * radius * sin(theta));
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
