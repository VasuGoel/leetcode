// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int rand40 = 40;
        while(rand40 >= 40)     
            rand40 = 7 * (rand7() - 1) + (rand7() - 1);
        return rand40 % 10 + 1;    
    }
};

/*

rand7() will get random 1 ~ 7
(rand7() - 1) * 7 + rand7() - 1 will get random 0 ~ 48
We discard 40 to 48, now we have rand40 equals to random 0 ~ 39.
We just need to return rand40 % 10 + 1 and we get random 1 ~ 10.

In 9/49 cases, we need to start over again.
In 40/49 cases, we call rand7() two times.

Overall, we need 49/40*2 = 2.45 calls of rand7() per rand10().


Intuition behind rand40():
Think of rand7() as having a 7 sided die.
Since we need rand10() (a 10 sided die) and 10 is greater than 7, we need to roll the 7 sided die multiple times.
Rolling the 7 sided die twice yields 49 different combinations:
(1,1)
(1,2)
(1,3)
...
(7,7)

Now we need to distinguish between these 49 different outcomes somehow. How can we map our two 7 sided die rolls to these different outcome numbers (1-49)?
The first thing that comes to mind is to multiply the two numbers in each tuple together. But that results in a non-uniform distribution because you would get
(1,1) = 1
(1,2) = 2
(2,1) = 2
See how the outcome of "2" has a chance of appearing twice, whereas the outcome of "1" has a chance of appearing once? This is because multiplication does not care about order.

One way to fix this problem is to think of each dice roll as the row/col of a 7x7 matrix.

    1  2  3  4  5  6  7
1   0  1  2  3  4  5  6
2   7  8  9  0  1  2  3
3   4  5  6  7  8  9  0
4   1  2  3  4  5  6  7
5   8  9  0  1  2  3  4
6   5  6  7  8  9
7

Now, we have 49 cells and we want to randomly pick a number from 1 to 10. That means, any number from 1 to 10 should have equal chance of being picked that is 1/10.
But we have 49 cells and only 10 numbers, so only way for uniform distribution is to number them by repeating the 1 to 10 sequences but after 40, we do not have enough cells to complete the 1 to 10 sequence.
Up to 40, we have four 1's and four 2's ... four 10's so they all have equal chance namely 4/40. So we have to discard in order to not skew the distribution (without this part, it is not a fair sampling).

*/
