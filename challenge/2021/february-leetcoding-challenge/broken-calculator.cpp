// O(log(Y/X)) time (we do Y/2 until Y is smaller than X), O(1) space. Greedy approach.
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        while(Y > X) {
            Y = (Y & 1) ? Y + 1 : Y / 2;
            res++;
        }
        return res + X - Y;
    }
};

/*

Intuition:

Considering how to change Y to X
Oper 1: Y = Y / 2, if Y is even
Oper 2: Y = Y + 1


Explanation:

If Y <= X, we won't do Y / 2 anymore
We will increase Y until it equals to X

So before that, while Y > X, we'll keep reducing Y, until it's smaller than X
If Y is odd, we can do only Y = Y + 1
If Y is even, if we plus 1 to Y, then Y is odd, we need to plus another 1
And because (Y + 1 + 1) / 2 = (Y / 2) + 1, 3 operations are more than 2
We always choose Y / 2 if Y is even


What we do:
If Y is even, Y = Y / 2
If Y is odd, Y = (Y + 1) / 2

*/
