// BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s (wordList.begin(), wordList.end());
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()) {
            int len = q.size();
            
            while(len--) {
                auto cur = q.front(); q.pop();
                string word = cur.first;
                int moves = cur.second;
                
                for(int i = 0; i < word.size(); i++) {
                    char c = word[i];
                    for(char j = 'a'; j <= 'z'; j++) {
                        word[i] = j;
                        
                        if(s.count(word)) {
                            if(word == endWord)     return moves+1;
                            
                            s.erase(word);
                            q.push({word, moves+1});
                        }
                    }
                    word[i] = c;
                }
            }
        }
        return 0;
    }
};
