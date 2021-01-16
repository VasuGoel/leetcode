// O(logn) time and space
class Solution {
public:
    double myPow(double x, int n) {
        return n >= 0 ? binaryExpo(x, n) : binaryExpo((double)1/x, abs(n));
    }
    
    // recursive binary exponentiation
    double binaryExpo(double a, int b) {
        if(!b)  return 1;
        
        double res = 0;
        double subprob = binaryExpo(a, b/2);
        res = subprob * subprob;
        if(b & 1)   res *= a;
        
        return res;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(logn) time, O(1) space.
class Solution {
public:
    double myPow(double x, int n) {
        return n >= 0 ? binaryExpo(x, n) : binaryExpo((double)1/x, abs(n));
    }
    
    // iterative binary exponentiation
    double binaryExpo(double a, int b) {
        if(!b)  return 1;
        
        double res = 1;
        while(b) {
            if(b & 1)   res *= a;
            a *= a;
            b /= 2;
        }
        return res;
    }
};
