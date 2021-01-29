// O(n•sqrt(n)) time, O(n) space DP
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1);
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j <= i; j++) {
                if(!dp[i-j*j]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};

/*

• dp[i] = 1, means first player to play 'i' stones will win.

• Base condition: dp[0] = 0, means first player with 0 stones will loose.

• Consider n = 8 stones and Alice plays (can only choose perfect number of stones) first,
    - if she picks 1 stone, problem becomes n = 7 stones when Bob plays first, in which case Bob looses.
    - if she picks 4 stones, problem becomes n = 4 stones when Bob plays first, in which case Bob wins.
    
    So , when n = 8 stones Alice should choose 1 stone and thus force Bob on a loosing state.


dp[n]    first       second

1         W            L
2         L            W
3         W            L
4         W            L
5         L            W
6         W            L
7         L            W
8         W            L

*/
