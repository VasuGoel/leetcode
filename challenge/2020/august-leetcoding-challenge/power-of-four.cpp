// O(1) time and space
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)  return false;
        return (n & (n-1)) == 0 and (n-1) % 3 == 0;
    }
};

/*

We're basically checking if the number 'n' is positive and power of 2 and (n-1) is divisible by 3.
For ex: 4, 16, 64, 256

*/


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(logn) time, O(1) space
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)  return false;
        
        while(n % 4 == 0)   
            n /= 4;
        return n == 1;
    }
};
