class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)  return {};
        vector<string> phone {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        int i = 0;
        string s;
        deque<string> q;
        q.push_back(s);
        
        while(q.front().size() != digits.size()) {
            int d = digits[i++];
            int count = q.size();
            
            while(count--) {
                string s = q.front();
                q.pop_front();
                
                for(char c: phone[d-'0'])   
                    q.push_back(s + c);
            }
        }
        return {q.begin(), q.end()};
    }
};
