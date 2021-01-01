// O(n) time and space, where n = arr length
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        // map first element of each piece to its position in pieces
        unordered_map<int, int> mp;
        for(int i = 0; i < pieces.size(); i++)  mp[pieces[i].front()] = i;
        
        // check if we can form arr using pieces
        int j = 0;
        while(j < arr.size()) {
            if(!mp.count(arr[j]))   return false;
            
            for(auto x: pieces[mp[arr[j]]]) {
                if(x != arr[j]) return false;
                j++;
            }
        }
        return true;
    }
};
