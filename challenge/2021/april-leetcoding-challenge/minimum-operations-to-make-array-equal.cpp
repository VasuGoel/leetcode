// O(1) time and space
class Solution {
public:
    int minOperations(int n) {
        return (n & 1) ? (n/2 * (n/2 + 1)) : (n/2 * n/2);
    }
};

/*

We know that given array is an array of first n odd numbers.
Case 1: When n is odd, say n = 5 => arr = [1, 3, 5, 7, 9]
Most optimal way to make all elements equal is to change all elements to middle 5
a) Take 2 from arr[3] = 7 and add to arr[1] = 3 to make arr[1] == arr[3] == 5
b) Take 4 from arr[4] = 9 and add to arr[0] = 1 to make arr[0] == arr[4] == 5
Total moves = 2 + 4 = 6 (Sum of first n/2 even numbers)

Case 2: When n is even, say n = 6 => arr = [1, 3, 5, 7, 9, 11]
Most optimal way to make all elements equal is to change all elements to mid value (5 + 7) / 2 = 6
a) Take 1 from arr[3] = 7 and add to arr[2] = 5 to make arr[2] == arr[3] == 6
b) Take 3 from arr[4] = 9 and add to arr[1] = 3 to make arr[1] == arr[4] == 6
c) Take 5 from arr[5] = 11 and add to arr[0] = 1 to make arr[0] == arr[5] == 6
Total moves = 1 + 3 + 5 = 9 (Sum of first n/2 odd numbers)

Math formulae:
1. Sum of first k odd number = (k • k)
2. Sum of first k even numbers = (k • (k + 1))

*/
