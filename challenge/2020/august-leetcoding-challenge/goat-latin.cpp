class Solution {
    const unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
    
public:
    string toGoatLatin(string S) {
        string res, word, end = "a";
        istringstream ss (S);
        
        while(ss >> word) {
            if(!vowels.count(tolower(word[0])))
                word = word.substr(1) + word[0];
                
            res  += word + "ma" + end + (ss.good() ? " " : "");
            end  += 'a';
        }
        return res;
    }
};
