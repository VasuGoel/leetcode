// O(1) time and space
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        return (n & (n - 1)) == 0;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(1) time and space
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        return __builtin_popcount(n) == 1;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(logn) time, O(1) space
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        while(n % 2 == 0)    n /= 2;
        return n == 1;
    }
};
