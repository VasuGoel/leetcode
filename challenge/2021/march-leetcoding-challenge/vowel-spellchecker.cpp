class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words (wordlist.begin(), wordlist.end());
        unordered_map<string, string> caps, devowels;
        
        for(string word: wordlist) {
            string lower = tolow(word), devowel = removeVowels(word);
            caps.insert({lower, word});
            devowels.insert({devowel, word});
        }
        
        vector<string> ret;
        for(string query: queries) {
            string lower = tolow(query), devowel = removeVowels(query);
            if(words.count(query))
                ret.push_back(query);
            else if(caps.count(lower))
                ret.push_back(caps[lower]);
            else if(devowels.count(devowel))
                ret.push_back(devowels[devowel]);
            else
                ret.push_back("");
        }
        return ret;
    }
    
    string tolow(string s) {
        for(char &c: s)
            c = tolower(c);
        return s;
    }
    
    string removeVowels(string s) {
        s = tolow(s);
        for(char &c: s)
            if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
                c = '#';
        return s;
    }
};
