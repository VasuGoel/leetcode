// O(n) time and space. Greedy approach.
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxfreq = 0;
        unordered_map<char,int> freq;
        
        // store frequency of occurence of each task and also find max freq
        for(char task: tasks)
            maxfreq = max(maxfreq, ++freq[task]);
        
        /* 
        say task 'T' has the max freq 'maxFreq', the number of CPU cycles to schedule first (maxFreq - 1) occurences of task 'T' will be (maxFreq - 1) * (n + 1) [where +1 in n+1 includes the cycle for task 'T']
        to schedule the last occurence of task 'T' traverse the freq hash map and increment the cycleCount if any task has the 'maxFreq' freq (of course that will include the task 'T' itself). Ex - "aabbbbbbccc", n = 2
        */
        int units = (maxfreq-1) * (n+1);
        for(auto f: freq)
            if(f.second == maxfreq)
                units++;
        
        // if number of tasks themselves are more than the cycle count computed above then return the number of tasks. Ex: "aaabbb", n = 0
        return max(units, (int)tasks.size());
    }
};
