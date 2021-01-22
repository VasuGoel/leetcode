// Brute force. O(n^2) time
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ret;
        
        for(int max = arr.size(); max >= 1; max--) {
            int pos = find(arr.begin(), arr.end(), max) - arr.begin();
            
            reverse(arr.begin(), arr.begin()+pos+1);
            ret.push_back(pos+1);
            
            reverse(arr.begin(), arr.begin()+max);
            ret.push_back(max);
        }
        return ret;
    }
};

/*

• Find the index i of the next maximum number x
• Reverse i+1 numbers, so that the x will be at arr[0]
• Reverse x numbers, so that x will be at arr[x-1]
• Repeat this process n times

Consider nums = {3, 2, 4, 1}

max = 4
{4, 2, 3, 1}
{1, 3, 2, 4}

max = 3
{3, 1, 2, 4}
{2, 1, 3, 4}

max = 2
{2, 1, 3, 4}
{1, 2, 3, 4}

max = 1
{1, 2, 3, 4}
{1, 2, 3, 4}

*/
