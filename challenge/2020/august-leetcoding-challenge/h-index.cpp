// O(n) time and space
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), sum = 0;
        vector<int> buckets (n+1);
        
        for(int c: citations)
            buckets[min(c, n)]++;
        
        for(int i = n; i >= 0; i--) {
            sum += buckets[i];
            if(sum >= i)    return i;
        }
        return -1;
    }
};

/*
                               --------------------  <- greater than size of array
Consider citations = {1, 4, 4, 12, 13, 53, 100, 344};

indices:    0   1   2   3   4   5   6   7   8
counts:         1           2               5

Start iterating from right to left and summing counts, return the first index where sum >= i
So, in case of above citations, h-index = 5

*/
