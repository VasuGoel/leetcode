// O(1) time push() and pop() operations, O(n) space
class FreqStack {
    int maxfreq = 0;
    // store frequency of each element
    unordered_map<int, int> freq;
    // maps frequency to stack (element with frequency n is pushed into n stacks, m[1], m[2], ..., m[n])
    unordered_map<int, stack<int>> mp;
    
public:
    void push(int x) {
        maxfreq = max(maxfreq, ++freq[x]);
        mp[freq[x]].push(x);
    }
    
    int pop() {
        int res = mp[maxfreq].top();
        mp[maxfreq].pop();
        if(mp[freq[res]--].empty())
            maxfreq--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
