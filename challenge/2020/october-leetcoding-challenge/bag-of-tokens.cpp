// O(n•logn) time, O(1) space
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        
        int res = 0, score = 0;
        int l = 0, r = tokens.size()-1;
        
        while(l <= r) {
            if(P >= tokens[l])
                P -= tokens[l++], score++;
            else if(score > 0)
                P += tokens[r--], score--;
            else
                break;
            
            res = max(res, score);
        }
        return res;
    }
};

/*

• Sort tokens
• Buy at the cheapest and sell at the most expensive
• Keep track of max points at any instance

*/
