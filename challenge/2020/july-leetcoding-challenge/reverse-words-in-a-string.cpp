// O(n) time, O(1) space, in-place. Using 2 pointer approach, the idea is to first remove extra spaces and reverse each individual words and at lastly reverse entire string
class Solution {
public:
    string reverseWords(string s) {
        int r = 0, n = s.size(), k = 0;
        
        while(r < n) {
            while(r < n and isspace(s[r]))  r++;    // skip spaces
            
            if(k and r < n)   s[k++] = ' ';         // add space to seperate words
            int l = k;
            while(r < n and !isspace(s[r])) 
                s[k++] = s[r++];
            reverse(s.begin()+l, s.begin()+k);      // reverse individual word
        }
        s.resize(k);                                // resize string (in case of extra spaces)
        reverse(s.begin(), s.end());                // reverse entire string
        return s;
    }
};


// –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––


// O(n) time and space. Using istringstream in C++.
class Solution {
public:
    string reverseWords(string s) {
        string res, word;
        istringstream ss(s);
        
        while(ss >> word)
            res = word + (res.empty() ? "" : " ") + res;
        
        return res;
    }
};
