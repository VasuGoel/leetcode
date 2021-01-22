// O(24) time. Checking all 4! = 24 permutations
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        
        do {
            if((arr[0] < 2 or (arr[0] == 2 and arr[1] < 4)) and arr[2] < 6)
                return to_string(arr[0]) + to_string(arr[1]) + ":" + to_string(arr[2]) + to_string(arr[3]);
        } 
        while(prev_permutation(arr.begin(), arr.end()));
        
        return "";
    }
};
