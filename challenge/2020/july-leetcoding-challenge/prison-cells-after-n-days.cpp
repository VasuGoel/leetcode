class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        // encode current cells state in 8 bit number
        bitset<8> cur;
        for(int i = 0; i < 8; i++)  cur[i] = cells[i];
        
        // map state to no. of days after start state it appears
        unordered_map<bitset<8>, int> states {{cur, 0}};
        
        for(int d = 1; d <= N; d++) {
            // compute next state using given rules
            bitset<8> next;
            for(int i = 1; i < 7; i++)
                next[i] = (cur[i-1] == cur[i+1]);
            
            // if next state is not previously present in map, insert it
            if(!states.count(next))     states.insert({next, d});
            // otherwise a cycle is present and return required state by skipping all cycles
            else {
                int cycle_length = d - states[next];
                
                vector<int> cell = decode(next);
                return prisonAfterNDays(cell, (N - d) % cycle_length);
            }
            cur = next;
        }
        return decode(cur);
    }
    
    // helper function to convert bitset state to a vector
    vector<int> decode(bitset<8> &state) {
        vector<int> cells (8);
        for(int i = 0; i < 8; i++)  cells[i] = state[i];
        return cells;
    }
};

/*

Since there are only eights cells in a row and each cell can be vacant or full (0 or 1), there are total 2^8 = 256 possible configurations.
However, we notice first and last cell will always be 0 after first transition, so total possible configurations are now, 2^6 = 64.

If we have a huge N day value (precisely, greater than total possible configurations or state space, here 64), the cell configurations are bound to repeat themselves, so we just need to find
the cycle length after which the sequence will be repeated. In other words, it is guaranteed that day 1 transition will repeat itself after 'cycle_len' transitions.

Consider we start on day 0, after subsequent transitions, we're at day/transition 'i' and we see current configuration has been seen before (hashmap store transition as key with transition# as value) 
that means all subsequent transitions will be repeated in a cycle, the cycle length will be 'i - 1', in the below case 'cycle_len' = 15 - 1 = 14.
Consider N = 100000 day, now rather than doing 100000 transitions, the required transition is ((n - i) % cycle_len) + 1

Transition #        Cells
0                   10010010    <- start day

1                   00010010
2                   01010010    
3                   01110010
4                   00100010
5                   00101010
6                   00111110
7                   00011100
8                   01001000    
9                   01001010
10                  01001110
11                  01000100
12                  01010100
13                  01111100
14                  00111000
15                  00010010    <- repetition from transition #1, cycle_len = 15-1 = 14

*/
