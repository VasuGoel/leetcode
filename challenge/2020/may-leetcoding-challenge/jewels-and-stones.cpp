// O(max(m, n)) or (m + n) time, O(1) space, where m = jewels length, and n = stones length
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        vector<bool> v(128);
        for(char j: jewels)     v[j] = 1;
        
        for(char s: stones)
            if(v[s])    res++;
        return res;
    }
};


// --------------------------------------------------------------------------------------------––


// O(max(m, n)) or (m + n) time, O(1) space, where m = jewels length, and n = stones length. Using bitset.
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        bitset<32> lower, upper;
        
        for(char j: jewels) {
            if(islower(j))  lower |= (1 << (j-'a'));
            else    upper |= (1 << (j-'A'));
        }
        
        for(char s: stones) {
            if(islower(s))  res += lower[s-'a'];
            else    res += upper[s-'A'];
        }
        return res;
    }
};
