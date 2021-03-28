// O(n) time, O(1) space
class Solution {
public:
    string originalDigits(string s) {
        vector<int> counts (10);
        
        for(char c: s) {
            if(c == 'z')    counts[0]++;
            if(c == 'w')    counts[2]++;
            if(c == 'u')    counts[4]++;
            if(c == 'x')    counts[6]++;
            if(c == 'g')    counts[8]++;
            
            if(c == 'o')    counts[1]++;
            if(c == 't')    counts[3]++;
            if(c == 'f')    counts[5]++;
            if(c == 's')    counts[7]++;
            if(c == 'i')    counts[9]++;
        }
        
        counts[1] -= (counts[0] + counts[2] + counts[4]);
        counts[3] -= (counts[2] + counts[8]);
        counts[5] -= counts[4];
        counts[7] -= counts[6];
        counts[9] -= (counts[5] + counts[6] + counts[8]);
        
        string res;
        for(int i = 0; i < 10; i++)
            res += string(counts[i], (char)i+'0');

        return res;
    }
};

/*

The even digits all have a unique letter while the odd digits all don't:

• zero: Only digit with z
• two: Only digit with w
• four: Only digit with u
• six: Only digit with x
• eight: Only digit with g

The odd ones each letters all also appear in other digit words:
• one, three, five, seven, nine

So the idea is to only count the unique letters for each number (since input is guaranteed to be valid), 
and if not possible count mutual characters with possible even numbers (wherever possible) and subtract their counts to get count for the odd number iteself.

0: zero     -> count 'z'
1: one      -> count 'o' - (counts[0] + counts[2] + counts[4])
2: two      -> count 'w'
3: three    -> count 't' - (counts[2] + counts[8])
4: four     -> count 'u'
5: five     -> count 'f' - (counts[4])
6: six      -> count 'x'
7: seven    -> count 's' - (counts[6])
8: eight    -> count 'g'
9: nine     -> count 'i' - (counts[5] + counts[6] + counts[8])

*/
