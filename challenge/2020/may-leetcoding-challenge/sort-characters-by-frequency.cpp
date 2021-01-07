// O(n) time and space. Bucket Sort.
class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<string> buckets(n+1);
        
        // count frequency of each character
        unordered_map<char, int> freq;
        for(char c: s)  freq[c]++;
        
        // iterate over all {character, frequency} pairs in map, and append character string to correct bucket
        for(auto e: freq)   
            buckets[e.second] += string(e.second, e.first);
        
        // return resultant string by append all strings, iterating from higher to lower bucket
        string res;
        for(int i = n; i ; i--)     res += buckets[i];
        return res;
    }
};


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(n • logn) time, O(1) space
class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128);
        for(char c: s)  freq[c]++;
        
        sort(s.begin(), s.end(), [&](char a, char b) -> bool {
            return make_pair(freq[a], a) > make_pair(freq[b], b);
        });
        return s;
    }
};
