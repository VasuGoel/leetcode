// O(1) time and space
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

/*

This problem is widely known as digit root problem, and has a congruence formula:
• dr(n) = 1 + (n - 1) % 9

From the formula, we can find that the result of this problem is periodic, with period (b-1).

Output sequence for decimals (b = 10):

input: 0 1 2 3 4 ...
output: 0 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 ....

*/


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Iterative solution
class Solution {
public:
    int addDigits(int num) {
        while(num >= 10) {
            int sum = 0;
            while(num) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};


// ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// Recursive solution
class Solution {
public:
    int addDigits(int num) {
        if(num < 10)    return num;
        return addDigits(next(num));
    }
    
    int next(int num) {
        int sum = 0;
        while(num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
